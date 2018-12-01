package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	words := make(map[string]int)
	input := bufio.NewScanner(os.Stdin)
	input.Split(bufio.ScanWords)
	for input.Scan() {
		words[input.Text()]++
	}
	for k, v := range words {
		fmt.Printf("%s\t%d\n", k, v)
	}
}
