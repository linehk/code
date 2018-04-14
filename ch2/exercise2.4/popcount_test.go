package popcount

import (
	"testing"
)

func PopCountByShifting(x uint64) int {
	n := 0
	for i := uint(0); i < 64; i++ {
		if x&(1<<i) != 0 {
			n++
		}
	}
	return 0
}

func BenchmarkPopCountByShifting(b *testing.B) {
	for i := 0; i < b.N; i++ {
		PopCountByShifting(0x1234567890ABCDEF)
	}
}

/*
goos: linux
goarch: amd64
pkg: gopl/ch2/exercise2.4
BenchmarkPopCountByShifting-8           50000000                29.5 ns/op
PASS
ok      gopl/ch2/exercise2.4       1.512s
*/
