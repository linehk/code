package popcount

import (
	"testing"
)

func PopCountByClearing(x uint64) int {
	n := 0
	for x != 0 {
		x = x & (x - 1) // clear rightmost non-zero bit
		n++
	}
	return n
}

func BenchmarkPopCountByClearing(b *testing.B) {
	for i := 0; i < b.N; i++ {
		PopCountByClearing(0x1234567890ABCDEF)
	}
}

/*
goos: linux
goarch: amd64
pkg: gopl/ch2/exercise2.5
BenchmarkPopCountByClearing-8           50000000                30.3 ns/op
PASS
ok      gopl/ch2/exercise2.5       1.552s
*/
