package singleLinkedList

import (
	"testing"
)

func TestSingleLinkedList(t *testing.T) {
	l := New()

	// insert empty list
	l.Insert(&node{3, nil}, l.head)
	t.Log(l.Show())

	// delete only one node
	l.Delete(l.head.next)
	t.Log(l.Show())

	l.Insert(&node{2, nil}, l.head)
	// insert after last node
	l.Insert(&node{1, nil}, l.head.next)
	t.Log(l.Show())

	// delete last node
	l.Delete(l.head.next.next)
	t.Log(l.Show())
}
