package utils

import (
	"math"
)

func Swap(s []interface{}, i, j int) {
	s[i], s[j] = s[j], s[i]
}

func IsSameSlice(a, b []interface{}) bool {
	if len(a) != len(b) {
		return false
	}
	if (a == nil) != (b == nil) {
		return false
	}
	for i, v := range a {
		if b[i] != v {
			return false
		}
	}
	return true
}

func MatrixMultply(a, b [][]int) [][]int {
	c := [][]int{
		{0, 0},
		{0, 0},
	}
	for i := 0; i < len(a); i++ {
		for j := 0; j < len(a); j++ {
			c[i][j] += a[i][j] * b[i][j]
		}
	}
	return c
}

func Average(s []int) int {
	var sum int
	for _, v := range s {
		sum += v
	}
	return sum / len(s)
}

func CopySlice(s []interface{}) []interface{} {
	newSlice := make([]interface{}, len(s))
	for i, v := range s {
		newSlice[i] = v
	}
	return newSlice
}

func FindMax(s []int) int {
	var max int
	for _, v := range s {
		max = v
		if v > max {
			max = v
		}
	}
	return max
}

func GCD(p, q int) int {
	if p < 0 && q < 0 {
		return 0
	}
	if q == 0 {
		return p
	}
	r := p % q
	return GCD(q, r)
}

func Reverse(s []interface{}) {
	length := len(s)
	for i := 0; i < length/2; i++ {
		Swap(s, i, length-i-1)
	}
}

func IsPrime(n int) bool {
	if n < 2 {
		return false
	}
	for i := 2; i*i <= n; i++ {
		if n%i == 0 {
			return false
		}
	}
	return true
}

// Newton's method
func Sqrt(c float64) float64 {
	err := 1e-15
	t := c
	for math.Abs(t-c/t) > err*t {
		t = (c/t + t) / 2.0
	}
	return t
}

// Calculate the hypotenuse of a triangle
func Hypotenuse(a, b float64) float64 {
	return Sqrt(a*a + b*b)
}

// Calculate Harmonic
func Harmonic(n int) float64 {
	sum := 0.0
	for i := 1; i <= n; i++ {
		sum += 1.0 / float64(i)
	}
	return sum
}
