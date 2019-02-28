// Fetchall fetches URLs in parallel and reports their times and sizes.
// go run main.go http://www.baidu.com https://www.tmall.com > out
package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
	"os"
	"time"
)

type result struct {
	data []byte
	secs float64
	err  error
}

func main() {
	ch1 := make(chan result)
	ch2 := make(chan result)
	for _, url := range os.Args[1:] {
		go timesFetch(url, ch1, ch2)
	}
	for _, url := range os.Args[1:] {
		fmt.Println(url)

		res1 := <-ch1
		res2 := <-ch2

		fmt.Println("first response:")
		fmt.Printf("%s\n", res1.data)
		fmt.Println(res1.err)

		fmt.Println("second response:")
		fmt.Printf("%s\n", res2.data)
		fmt.Println(res2.err)

		fmt.Printf("first resp secs: %.2fs; second resp secs: %.2fs\n",
			res1.secs, res2.secs)
	}
}

func timesFetch(url string, ch1, ch2 chan<- result) {
	fetch(url, ch1)
	fetch(url, ch2)
}

func fetch(url string, ch chan<- result) {
	start := time.Now()
	resp, err := http.Get(url)
	if err != nil {
		ch <- result{err: err}
		return
	}

	data, err := ioutil.ReadAll(resp.Body)
	resp.Body.Close() // don't leak resources
	if err != nil {
		ch <- result{err: err}
		return
	}
	secs := time.Since(start).Seconds()
	ch <- result{data: data, secs: secs, err: nil}
}
