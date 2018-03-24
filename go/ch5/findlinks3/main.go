package main

import (
	"fmt"
	"links"
	"log"
	"os"
)

func breadthFirst(f func(item string) []string, worlist []string) {
	seen := make(map[string]bool)
	for len(worlist) > 0 {
		items := worlist
		worlist = nil
		for _, item := range items {
			if !seen[item] {
				seen[item] = true
				worlist = append(worlist, f(item)...)
			}
		}
	}
}

func crawl(url string) []string {
	fmt.Println(url)
	list, err := links.Extract(url)
	if err != nil {
		log.Print(err)
	}
	return list
}

func main() {
	breadthFirst(crawl, os.Args[1:])
}
