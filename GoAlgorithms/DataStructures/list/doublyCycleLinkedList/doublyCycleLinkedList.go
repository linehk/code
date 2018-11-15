package doublyCycleLinkedList

import (
	"fmt"
)

type node struct {
	value interface{}
	next  *node
	prev  *node
}

type list struct {
	head *node
}

func New() *list {
	l := new(list)
	l.head = new(node)
	l.head.value = nil
	l.head.next = l.head
	l.head.prev = l.head
	return l
}

func (l *list) Insert(n, mark *node) {
	n.next = mark.next
	n.prev = mark
	mark.next.prev = n
	mark.next = n
}

func (l *list) Delete(n *node) {
	n.prev.next = n.next
	n.next.prev = n.prev
}

func (l list) Show() string {
	format := ""
	cur := l.head
	for cur.next != l.head {
		cur = cur.next
		format += fmt.Sprintf("%v", cur.value)
		if cur.next != l.head {
			format += fmt.Sprint("->")
		}
	}
	return format
}
