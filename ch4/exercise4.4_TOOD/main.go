package main

import (
	"fmt"
)

func gcd(a, b int) int {
	for b > 0 {
		a, b = b, a%b
	}
	return a
}

func rotate(s []int, n int) {
	length := len(s)
	n = (n + length) % length
	gcd := gcd(length, n)
	loop := length / gcd

	for i := 0; i < gcd; i++ {
		temp := s[i]
		j := 0
		for ; j < loop-1; j++ {
			s[(i+j*n)%length] = s[(i+j*n+n)%length]
		}
		s[(i+j*n)%length] = temp
	}
}

func main() {
	a := [...]int{0, 1, 2, 3, 4, 5}
	rotate(a[:], 2)
	fmt.Println(a)
}
