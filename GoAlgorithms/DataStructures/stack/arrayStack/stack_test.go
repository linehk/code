package arrayStack

import (
	"testing"
)

func TestStack(t *testing.T) {
	s := New(3)
	s.Push(1)
	s.Push(2)
	s.Push(3)
	t.Log(s.elements)

	s.Push(4)
	t.Log(s.elements)

	t.Log(s.Pop())
	t.Log(s.Pop())
	t.Log(s.Pop())
	t.Log(s.elements)

	t.Log(s.Pop())
	t.Log(s.elements)
}
