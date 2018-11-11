package doublyLinkedList

import (
	"testing"
)

func TestDoublyLinkedList(t *testing.T) {
	l := New()
	l.Insert(&node{3, nil, nil}, l.head)
	t.Log(l.Show())

	l.Delete(l.head.next)
	t.Log(l.Show())

	l.Insert(&node{2, nil, nil}, l.head)
	l.Insert(&node{1, nil, nil}, l.head)
	t.Log(l.Show())

	l.Delete(l.head.next)
	t.Log(l.Show())
}
