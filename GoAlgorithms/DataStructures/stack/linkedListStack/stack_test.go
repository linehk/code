package linkedListStack

import (
	"testing"
)

func TestStack(t *testing.T) {
	s := New()
	s.Push(1)
	s.Push(2)
	s.Push(3)

	t.Log(s.Pop())
	t.Log(s.Pop())
	t.Log(s.Pop())

	t.Log(s.Pop())
}
