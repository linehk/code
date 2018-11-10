package utils

import (
	"testing"
)

func TestSwap(t *testing.T) {
	elts := []interface{}{1, 'a', "aa"}
	i := 0
	j := 2
	Swap(elts, i, j)
	want := []interface{}{"aa", 'a', 1}
	got := elts
	if !IsSameSlice(got, want) {
		t.Errorf("want %v, got %v\n", want, got)
	}
}

func TestIsSameSlice(t *testing.T) {
	s1 := []interface{}{1, 2, 3}
	s2 := []interface{}{1, 2, 3}
	want := true
	got := IsSameSlice(s1, s2)
	if got != want {
		t.Errorf("want %v, got %v\n", want, got)
	}
}

func TestMatrixMultply(t *testing.T) {
	a := [][]int{
		{2, 2},
		{2, 2},
	}
	b := [][]int{
		{2, 2},
		{2, 2},
	}

	want := [][]int{
		{4, 4},
		{4, 4},
	}
	got := MatrixMultply(a, b)
	for i := 0; i < len(got); i++ {
		for j := 0; j < len(got); j++ {
			if got[i][j] != want[i][j] {
				t.Errorf("want %v, got %v\n", want, got)
			}
		}
	}
}

func TestAverage(t *testing.T) {
	elts := []int{2, 2, 2, 2}

	want := 2
	got := Average(elts)
	if got != want {
		t.Errorf("want %v, got %v\n", want, got)
	}
}

func TestCopySlice(t *testing.T) {
	elts := []interface{}{1, 2, 3}

	want := elts
	got := CopySlice(elts)
	if !IsSameSlice(got, want) {
		t.Errorf("want %v, got %v\n", want, got)
	}
}

func TestFindMax(t *testing.T) {
	elts := []int{1, 2, 3, 4, 5}

	want := 5
	got := FindMax(elts)
	if got != want {
		t.Errorf("want %v, got %v\n", want, got)
	}
}

func TestGCD(t *testing.T) {
	p := 4
	q := 8

	want := 4
	got := GCD(p, q)
	if got != want {
		t.Errorf("want %v, got %v\n", want, got)
	}
}

func TestReverse(t *testing.T) {
	elts := []interface{}{1, 2, 3}

	Reverse(elts)
	want := []interface{}{3, 2, 1}
	got := elts
	if !IsSameSlice(got, want) {
		t.Errorf("want %v, got %v\n", want, got)
	}
}

func TestIsPrime(t *testing.T) {
	prime := 5

	want := true
	got := IsPrime(prime)
	if got != want {
		t.Errorf("want %v, got %v\n", want, got)
	}
}

func TestSqrt(t *testing.T) {
	num := 4.0

	want := 2.0
	got := Sqrt(num)
	if got != want {
		t.Errorf("want %v, got %v\n", want, got)
	}
}

func TestHypotenuse(t *testing.T) {
	a := 3.0
	b := 4.0

	want := 5.0
	got := Hypotenuse(a, b)
	if got != want {
		t.Errorf("want %v, got %v\n", want, got)
	}
}

func TestHarmonic(t *testing.T) {
	n := 3

	want := 11.0 / 6.0
	got := Harmonic(n)
	if got != want {
		t.Errorf("want %v, got %v\n", want, got)
	}
}
