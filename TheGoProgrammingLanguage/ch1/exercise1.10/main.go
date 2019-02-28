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
	data    []byte
	elapsed time.Duration
	err     error
}

func main() {
	ch1 := make(chan result)
	ch2 := make(chan result)
	for _, url := range os.Args[1:] {
		go fetch(url, ch1)
		go fetch(url, ch2)
	}
	for _, url := range os.Args[1:] {
		fmt.Println(url)
		firstResp := <-ch1
		secondResp := <-ch2

		fmt.Println("first response:")
		fmt.Printf("%s\n", firstResp.data)
		fmt.Println(firstResp.err)

		fmt.Println("second response:")
		fmt.Printf("%s\n", secondResp.data)
		fmt.Println(secondResp.err)

		fmt.Printf("first elapsed: %s, second elapsed: %s\n",
			firstResp.elapsed, secondResp.elapsed)
	}
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
	elapsed := time.Since(start)
	ch <- result{data: data, elapsed: elapsed, err: nil}
	close(ch)
}
