package echo

import (
	"testing"
)

// 500000 3426 ns/op
func BenchmarkEcho1(b *testing.B) {
	for i := 0; i < b.N; i++ {
		Echo1()
	}
}

// 500000 3512 ns/op
func BenchmarkEcho2(b *testing.B) {
	for i := 0; i < b.N; i++ {
		Echo2()
	}
}

// 500000 3419 ns/op
func BenchmarkEcho3(b *testing.B) {
	for i := 0; i < b.N; i++ {
		Echo3()
	}
}
