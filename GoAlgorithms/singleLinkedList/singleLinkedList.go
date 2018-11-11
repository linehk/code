// SingleLinkedList with head node
package singleLinkedList

import (
	"fmt"
)

type node struct {
	value interface{}
	next  *node
}

type list struct {
	head *node
}

func New() *list {
	l := new(list)
	n := new(node)
	n.value = nil
	n.next = nil
	l.head = n
	return l
}

func (l *list) Insert(n, mark *node) {
	n.next = mark.next
	mark.next = n
}

func (l *list) Delete(n *node) {
	pre := l.head
	for pre.next != n {
		pre = pre.next
	}

	pre.next = n.next
}

func (l list) Show() string {
	format := ""
	cur := l.head
	for cur.next != nil {
		cur = cur.next
		format += fmt.Sprintf("%v", cur.value)
		if cur.next != nil {
			format += fmt.Sprint("->")
		}
	}
	return format
}
