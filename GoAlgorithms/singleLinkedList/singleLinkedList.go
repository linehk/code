// 带头结点的单链表
package singleLinkedList

import (
        "errors"
        "fmt"
)

type node struct {
	value interface{}
	next  *node
}

type SingleLinkedList struct {
	length int
	head   *node
}

func NewNode(v interface{}) *node {
	return &node{v, nil}
}

func NewSingleLinkedList() *SingleLinkedList {
	return &SingleLinkedList{0, NewNode(nil)}
}

func InitSingleLinkedList(s []interface{}) *SingleLinkedList {
	n := NewSingleLinkedList()
	for _, v := range s {
	        n.InsertToTail(v)
	}
	return n
}

func (s SingleLinkedList) ToSlice() []interface{} {
        slice := make([]interface{}, s.length)
        cur := s.head.next
        for i := range slice {
                slice[i] = cur.GetValue()
                cur = cur.next
        }
        return slice
}


func (n node) GetValue() interface{} {
	return n.value
}

func (n node) GetNext() *node {
	return n.next
}

func (s *SingleLinkedList) InsertAfter(n *node, v interface{}) bool {
	if n == nil {
		return false
	}
	newNode := NewNode(v)
	oldNext := n.next
	n.next = newNode
	newNode.next = oldNext
	s.length++
	return true
}

func (s *SingleLinkedList) InsertBefore(n *node, v interface{}) bool {
	if n == nil || n == s.head {
		return false
	}
	pre := s.head
	if pre.next != n {
		pre = pre.next
	}
	newNode := NewNode(v)
	pre.next = newNode
	newNode.next = n
	s.length++
	return true
}

func (s *SingleLinkedList) InsertToHead(v interface{}) bool {
	return s.InsertAfter(s.head, v)
}

func (s *SingleLinkedList) InsertToTail(v interface{}) bool {
	cur := s.head
	for cur.next != nil {
		cur = cur.next
	}
	return s.InsertAfter(cur, v)
}

func (s *SingleLinkedList) FindByIndex(index int) (*node, error) {
	if index < 0 || index >= s.length {
		return nil, errors.New("index should < 0 and >= s.length")
	}
	cur := s.head.next
	for i := 0; i < index; i++ {
		cur = cur.next
	}
	return cur, nil
}

func (s *SingleLinkedList) Delete(n *node) bool {
	if n == nil {
		return false
	}

	pre := s.head
	if pre.next != n {
		pre = pre.next
	}

	pre.next = n.next
	n = nil
	s.length--
	return true
}

func (s SingleLinkedList) Show() string {
	cur := s.head.next
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

func (s *SingleLinkedList) Reverse() {
	// if s.head == nil || s.head.next == nil || s.head.next.next == nil {
	//         return nil
	// }

	if s.length < 3 {
		return
	}

	var pre *node
	cur := s.head.next
	for cur != nil {
		tmp := cur.next
		cur.next = pre
		pre = cur
		cur = tmp
	}
	s.head.next = pre
}
