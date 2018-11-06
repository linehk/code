package utils

import (
        "testing"
)

func TestSwap(t *testing.T) {
        got := []interface{}{1, 2, 3}
        i := 0
        j := 2
        want := []interface{}{3, 2, 1}
        Swap(got, i, j)
        if !IsSameSlice(got, want) {
                t.Errorf("want %v, got %v\n", want, got)
        }
}

func TestIsSameSlice(t *testing.T) {
        s1 := []interface{}{1, 2, 3}
        s2 := []interface{}{1, 2, 3}
        if got := IsSameSlice(s1, s2); !got {
                t.Errorf("want ok, got %t\n", got)
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
        c := [][]int{
                {4, 4},
                {4, 4},
        }
        got := MatrixMultply(a, b)
        for i := 0; i < len(got); i++ {
                for j := 0; j < len(got); j++ {
                        if got[i][j] != c[i][j] {
                                t.Errorf("want %v, got %v\n", c[i][j], got[i][j])
                        }
                }
        }
}

func TestAverage(t *testing.T) {
        s := []int{2, 2, 2, 2}
        got := Average(s)
        want := 2
        if got != want {
                t.Errorf("want %d, got %d\n", want, got)
        }
}

func TestCopySlice(t *testing.T) {
        want := []interface{}{1, 2, 3}
        got := CopySlice(want)
        if !IsSameSlice(want, got) {
                t.Errorf("want %v, got %v\n", want, got)
        }
}

func TestFindMax(t *testing.T) {
        s := []int{1, 2, 3, 4, 5}
        want := 5
        got := FindMax(s)
        if got != want {
                t.Errorf("want %d, got %d\n", want, got)
        }
}

func TestGCD(t *testing.T) {
        want := 4
        p := 4
        q := 8
        got, ok := GCD(p, q)

        if got != want || !ok {
                t.Errorf("want %d, got %d\n", want, got)
        }
}

func TestReverse(t *testing.T) {
        got := []interface{}{1, 2, 3}
        want := []interface{}{3, 2, 1}
        Reverse(got)
        if !IsSameSlice(got, want) {
                t.Errorf("want %v, got %v\n", want, got)
        }
}

func TestIsPrime(t *testing.T) {
        n := 5
        if ok := IsPrime(n); !ok {
                t.Errorf("%d is prime? %t\n", n, ok)
        }
}

func TestSqrt(t *testing.T) {
        n := 4.0
        want := 2.0
        got := Sqrt(n)
        if got != want {
                t.Errorf("want %f, got %f\n", want, got)
        }
}

func TestHypotenuse(t *testing.T) {
        a := 3.0
        b := 4.0
        want := 5.0

        got := Hypotenuse(a, b)
        if got != want {
                t.Errorf("want %f, got %f\n", want, got)
        }
}

func TestHarmonic(t *testing.T) {
        n := 3
        want := 11.0 / 6.0
        got := Harmonic(n)

        if got != want {
                t.Errorf("want %f, got %f\n", want, got)
        }
}