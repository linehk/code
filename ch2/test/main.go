package main

import (
	"fmt"
)

func main() {
	fmt.Println(fib(2))
	s := 1
	p := &s
	p = nil
	fmt.Println(p)
}

func gcd(x, y int) int {
	if y != 0 {
		x, y = y, x%y
	}
	return x
}

func fib(n int) int {
	x, y := 0, 1
	for i := 0; i < n; i++ {
		x, y = y, x+y
	}
	return x
}
