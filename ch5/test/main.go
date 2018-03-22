package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(hypot(3, 4))
	fmt.Printf("%T\n", add)
	fmt.Printf("%T\n", sub)
	fmt.Printf("%T\n", first)
	fmt.Printf("%T\n", zero)
}

func hypot(x, y float64) float64 {
	return math.Sqrt(x*x + y*x)
}

func add(x int, y int) int   { return x + y }
func sub(x, y int) (z int)   { z = x - y; return }
func first(x int, _ int) int { return x }
func zero(int, int) int      { return 0 }
