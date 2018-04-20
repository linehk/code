package main

import (
	"fmt"
)

func main() {
	b := []byte{'1', '2', '3'}
	reverse(b)
	for _, c := range b {
		fmt.Printf("%q\n", c)
	}
}

func reverse(b []byte) {
	for i, j := 0, len(b)-1; i < j; i, j = i+1, j-1 {
		b[i], b[j] = b[j], b[i]
	}
}
