package doublyLinkedList

import (
        "fmt"
)

type node struct {
        value interface{}
        next *node
        prev *node
}

type list struct {
        head *node
}

func New() *list {
        l := new(list)
        l.head = new(node)
        l.head.next = nil
        l.head.prev = nil
        return l
}

func (l *list) Insert(n, mark *node) {
        n.next = mark.next
        n.prev = mark
        if mark.next != nil && mark.prev != nil {
                mark.next.prev = n
        }
        mark.next = n
}

func (l *list) Delete(n *node) {
        n.prev.next = n.next
        n.next.prev = n.prev

        n.value = nil
        n.next = nil
        n.prev = nil
        n = nil
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