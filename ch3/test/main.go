package main

import (
	"fmt"
	"math/cmplx"
)

func main() {
	x := 1 + 2i
	z := 1 + 2i
	if x == z {
		fmt.Println("x == z")
	}
	y := 3 + 4i
	fmt.Println(cmplx.Sqrt(-1))
	fmt.Println(x * y)
	fmt.Println(real(x * y))
	fmt.Println(imag(x * y))
	fmt.Println(1i * 1i)
}
