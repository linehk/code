package main

import (
	"fmt"
)

func main() {
	a := []string{"a", "b", "b", "b", "c", "b"}
	remove(a)
	fmt.Println(a)
}

func remove(s []string) []string {
	for i := 0; i < len(s)-1; i++ {
		if s[i] == s[i+1] {
			copy(s[i:], s[i+1:])
			s = s[:len(s)-1]
			i--
		}
	}
	return s
}
