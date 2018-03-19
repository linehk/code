package main

import (
	"fmt"
	"unicode"
)

func main() {
	fmt.Printf("%s\n", replace([]byte("a   a")))
}

func replace(slice []byte) []byte {
	for i := 0; i < len(slice)-1; i++ {
		if unicode.IsSpace(rune(slice[i])) && slice[i] == slice[i+1] {
			copy(slice[i:], slice[i+1:])
			slice = slice[:len(slice)-1]
			i--
		}
	}
	return slice
}
