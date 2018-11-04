package GoAlgorithms

import (
        "fmt"
        "math"
)

// 交换数组中的元素
func Swap(array []int, i, j int) {
	array[i], array[j] = array[j], array[i]
}

// 判断两个数组是否相同
func IsSameArray(array []int, anotherArray []int) bool {
	if len(array) != len(anotherArray) {
		return false
	}
	if (array == nil) != (anotherArray == nil) {
		return false
	}
	for k, v := range array {
		if anotherArray[k] != v {
			return false
		}
	}
	return true
}

// 矩阵（方阵）相乘
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

// 求平均数
func Average(array []int) int {
	var sum int
	for _, v := range array {
		sum += v
	}
	return sum / len(array)
}

// 复制数组
func CopyArray(array []int) []int {
	newArray := make([]int, len(array), cap(array))
	for k, v := range array {
		newArray[k] = v
	}
	return newArray
}

// 寻找最大值
func FindMax(array []int) int {
	var max int
	for _, v := range array {
		max = v
		if v > max {
			max = v
		}
	}
	return max
}

// 计算两个非负整数的最大公约数
func GCD(p, q int) (int, bool) {
	if p < 0 && q < 0 {
		return 0, false
	}
	if q == 0 {
		return p, true
	}
	r := p % q
	return GCD(q, r)
}

// 反转数组
func Reverse(array []int) {
	len := len(array)
	for i := 0; i < len/2; i++ {
		Swap(array, i, len-i-1)
	}
}

// 判断是否是素数
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

// 计算平方根（牛顿迭代法）
func Sqrt(c float64) float64 {
        if c < 0 {
                fmt.Errorf("c shoule positive")
        }
        err := 1e-15
        t := c
        for math.Abs(t - c / t) > err * t {
                t = (c / t + t) / 2.0
        }
        return t
}

// 计算三角形的斜边
func Hypotenuse(a, b float64) float64 {
        return Sqrt(a*a+b*b)
}

// 计算调和级数
func Harmonic(n int) float64 {
        sum := 0.0
        for i := 1; i <= n; i++ {
                sum += 1.0 / float64(i)
        }
        return sum
}