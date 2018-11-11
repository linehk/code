// CycleSingleLinkedList with head node
package cycleSingleLinkedList

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
	l.head = new(node)
	l.head.value = nil
	l.head.next = l.head
	return l
}

func (l *list) Insert(n, mark *node) {
	n.next = mark.next
	mark.next = n
}

func (l *list) Delete(n *node) {
	pre := n
	for pre.next != n {
		pre = pre.next
	}

	pre.next = n.next

        n.value = nil
	n.next = nil
	n = nil
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
