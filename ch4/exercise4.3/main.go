package main

import (
	"fmt"
)

func main() {
	a := [6]int{0, 1, 2, 3, 4, 5}
	reversePoint1(&a)
	fmt.Println(a)
	reversePoint2(&a)
	fmt.Println(a)
}

func reversePoint1(s *[6]int) {
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}
}

func reversePoint2(p *[6]int) {
	for i, j := 0, len(*p)-1; i < j; i, j = i+1, j-1 {
		(*p)[i], (*p)[j] = (*p)[j], (*p)[i]
	}
}
