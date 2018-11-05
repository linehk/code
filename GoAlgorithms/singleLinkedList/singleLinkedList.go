package singleLinkedList

import (
        "fmt"
)

type node struct {
        value interface{}
        next *node
}

type SingleLinkedList struct {
        len int
        head *node
}

func NewNode(v interface{}) *node {
        return &node{v, nil}
}

func NewSingleLinkedList() *SingleLinkedList {
        return &SingleLinkedList{0, NewNode(0)}
}

func InitSingleLinkedList(array []int) *SingleLinkedList {
        s := NewSingleLinkedList()
        h := s.head
        for _, v := range array {
                s.InsertAfter(h, v)
                h = h.next
        }
        return s
}

func (n node) GetValue() interface{} {
        return n.value
}

func (n node) GetNext() *node {
        return n.next
}

func (l *SingleLinkedList) InsertAfter(n *node, v interface{}) bool {
        if n == nil {
                return false
        }
        newNode := NewNode(v)
        oldNext := n.next
        n.next = newNode
        newNode.next = oldNext
        l.len++
        return true
}

func (l *SingleLinkedList) InsertBefore(n *node, v interface{}) bool {
        if n == nil || n == l.head {
                return false
        }
        pre := l.head
        cur := l.head.next
        for cur != n {
                pre = cur
                cur = cur.next
        }
        if cur == nil {
                return false
        }
        newNode := NewNode(v)
        pre.next = newNode
        newNode.next = cur
        l.len++
        return true
}

func (l *SingleLinkedList) InsertToHead(v interface{}) bool {
        return l.InsertAfter(l.head, v)
}

func (l *SingleLinkedList) InsertToTail(v interface{}) bool {
        cur := l.head
        if cur.next != nil {
                cur = cur.next
        }
        return l.InsertAfter(cur, v)
}

func (l *SingleLinkedList) FindByIndex(index int) *node {
        if index < 1 || index > l.len {
                return nil
        }
        cur := l.head.next
        for i := 1; i < index; i++ {
                cur = cur.next
        }
        return cur
}

func (l *SingleLinkedList) Delete(n *node) bool {
        if n == nil {
                return false
        }

        pre := l.head
        cur := l.head.next
        for cur != nil {
                if cur == n {
                        break
                }
                pre = cur
                cur = cur.next
        }
        if cur == nil {
                return false
        }
        pre.next = n.next
        n = nil
        l.len--
        return true
}

func (l SingleLinkedList) Show() string {
        cur := l.head.next
        format := ""
        for cur != nil {
                format += fmt.Sprintf("%+v", cur.GetValue())
                cur = cur.next
                if cur != nil {
                        format += "->"
                }
        }
        return format
}

func (l *SingleLinkedList) Reverse() {
        // if l.head == nil || l.head.next == nil || l.head.next.next == nil {
        //         return nil
        // }

        if l.len < 3 {
                return
        }

        var pre *node
        cur := l.head.next
        for cur != nil {
                tmp := cur.next
                cur.next = pre
                pre = cur
                cur = tmp
        }
        l.head.next = pre
}
