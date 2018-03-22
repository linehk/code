package main

import (
	"fmt"
	"os"

	"golang.org/x/net/html"
)

func main() {
	doc, err := html.Parse(os.Stdin)
	if err != nil {
		fmt.Fprintf(os.Stderr, "outline: %v\n", err)
	}
	s := outline(nil, doc)
	fmt.Println(s)
	countSameElement(s)
}

func outline(stack []string, n *html.Node) []string {
	if n.Type == html.DocumentNode {
		stack = append(stack, n.Data)
	}
	for c := n.FirstChild; c != nil; c = n.NextSibling {
		outline(stack, c)
	}
	return stack
}

func countSameElement(element []string) {
	one, two, three, four := 0, 0, 0, 0
	for i := 0; i < len(element)-1; i++ {
		if element[1] == element[i] {
			one++
			fmt.Println("%s = %d", element[1], one)
		}
		if element[2] == element[i] {
			two++
			fmt.Println("%s = %d", element[2], two)
		}
		if element[3] == element[i] {
			three++
			fmt.Println("%s = %d", element[3], three)
		}
		if element[4] == element[i] {
			four++
			fmt.Println("%s = %d", element[4], four)
		}

	}
}
