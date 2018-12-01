package main

import (
	"crypto/sha256"
	"fmt"
)

var s1 string
var s2 string

func main() {
	c1 := sha256.Sum256([]byte("x"))
	for _, c := range c1 {
		s1 += fmt.Sprintf("%b", c)
	}

	c2 := sha256.Sum256([]byte("X"))
	for _, c := range c2 {
		s2 += fmt.Sprintf("%b", c)
	}

	fmt.Println(diffString(s1, s2))
}

func diffString(s1, s2 string) int {
	var count int
	var l int
	var d int
	if len(s1) > len(s2) {
		l = len(s2)
		d = len(s1) - len(s2)
	} else {
		l = len(s1)
		d = len(s2) - len(s1)
	}

	for i := 0; i < l; i++ {
		if s1[i] != s2[i] {
			count++
		}
	}
	return count + d
}
