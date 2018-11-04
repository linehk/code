package GoAlgorithms

import (
        "testing"
)

func TestSwap(t *testing.T) {
        array := []int{1, 2, 3}
        swapArray := []int{3, 2, 1}
        i := 0
        j := 2
        Swap(array, i, j)
        if !IsSameArray(array, swapArray) {
                t.Error("didn't swap")
        }
}

func TestIsSameArray(t *testing.T) {
        array := []int{1, 2, 3}
        anotherArray := []int{1, 2, 3}
        if !IsSameArray(array, anotherArray) {
                t.Error("array isn't same")
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
        matrixMultply := MatrixMultply(a, b)
        if !IsSameArray(c[0], matrixMultply[0]) && !IsSameArray(c[1], matrixMultply[1]) {
                t.Error("didn't multply")
        }
}

func TestAverage(t *testing.T) {
        array := []int{2, 2, 2, 2}
        average := Average(array)
        if average != 2 {
                t.Errorf("average is %d\n", average)
        }
}

func TestCopyArray(t *testing.T) {
        array := []int{1, 2, 3}
        anotherArray := CopyArray(array)
        if !IsSameArray(array, anotherArray) {
                t.Errorf("fail\n")
        }
}

func TestFindMax(t *testing.T) {
        array := []int{1, 2, 3, 4, 5}
        max := 5
        testMax := FindMax(array)
        if testMax != max {
                t.Errorf("max is %d\n", testMax)
        }
}

func TestGCD(t *testing.T) {
        if gcd, ok := GCD(4, 8); ok {
                if gcd != 4 {
                        t.Errorf("p = %d, q = %d, gcd = %d is fail\n", 4, 8, gcd)
                }
        }
}

func TestReverse(t *testing.T) {
        array := []int{1, 2, 3}
        reverseArray := []int{3, 2, 1}
        Reverse(array)
        if !IsSameArray(array, reverseArray) {
                t.Errorf("fail\n")
        }
}

func TestIsPrime(t *testing.T) {
        prime := 5
        if !IsPrime(prime) {
                t.Errorf("%d is prime\n", prime)
        }
}

func TestSqrt(t *testing.T) {
        n := 4.0
        nSqrt := 2.0
        if testSqrtn := Sqrt(n); testSqrtn != nSqrt {
                t.Errorf("%f should be %f\n", testSqrtn, nSqrt)
        }
}

func TestHypotenuse(t *testing.T) {
        a := 3.0
        b := 4.0
        c := 5.0
        if testc := Hypotenuse(a, b); testc != c {
                t.Errorf("%f %f -> %f shoule be %f\n", a, b, testc, c)
        }
}

func TestHarmonic(t *testing.T) {
        result := 11.0 / 6.0
        if testResult := Harmonic(3); testResult != result {
                t.Errorf("3 harmonic shoule be %f, insert of %f\n", result, testResult)
        }
}