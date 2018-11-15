package array

import (
	"testing"
)

func TestArray(t *testing.T) {
	a := New(10)
	t.Log(a.len, a.cap)

	a.Insert(0, 0)
	t.Log(a.elements)

	a.Delete(0)
	t.Log(a.elements)

	a.Insert(0, 1)
	a.Insert(1, 2)
	a.Insert(2, 3)
	a.Insert(1, 99)
	t.Log(a.elements)

	a.Delete(1)
	t.Log(a.elements)
}
