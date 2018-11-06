package utils

import (
        "fmt"
        "math"
)

// 交换 Slice 中的元素
func Swap(s []interface{}, i, j int) {
        s[i], s[j] = s[j], s[i]
}

// 判断两个 Slice 是否相同
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
func Average(s []int) int {
	var sum int
	for _, v := range s {
		sum += v
	}
	return sum / len(s)
}

// 复制 Slice
func CopySlice(s []interface{}) []interface{} {
	newSlice := make([]interface{}, len(s))
	for i, v := range s {
	        newSlice[i] = v
	}
	return newSlice
}

// 寻找最大值
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

// 反转 Slice
func Reverse(s []interface{}) {
	len := len(s)
	for i := 0; i < len/2; i++ {
		Swap(s, i, len-i-1)
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