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

func main() {
	start := time.Now()
	ch := make(chan string)
	ch2 := make(chan string)
	for _, url := range os.Args[1:] {
		go fetch(url, ch)
		go fetch(url, ch2)
	}
	for range os.Args[1:] {
		fmt.Println(<-ch)
		fmt.Println(<-ch2)
	}
	fmt.Printf("%.2fs elapsed\n", time.Since(start).Seconds())
}

func fetch(url string, ch chan<- string) {
	start := time.Now()
	resp, err := http.Get(url)
	if err != nil {
		ch <- fmt.Sprint(err) // sent to channel ch
		return
	}

	b, err := ioutil.ReadAll(resp.Body)
	resp.Body.Close() // don't leak resources
	if err != nil {
		ch <- fmt.Sprintf("while reading %s: %v", url, err)
		return
	}
	secs := time.Since(start).Seconds()
	ch <- fmt.Sprintf("%s\n%.2f", b, secs)
}
