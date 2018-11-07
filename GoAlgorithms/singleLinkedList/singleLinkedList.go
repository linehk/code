// SingleLinkedList with head node
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

func (n node) GetValue() interface{} {
	return n.value
}

func (n node) GetNext() *node {
	return n.next
}

func NewSingleLinkedList() *SingleLinkedList {
	return &SingleLinkedList{0, NewNode(nil)}
}

func InitSingleLinkedList(s []interface{}) (*SingleLinkedList, error) {
	n := NewSingleLinkedList()
	for _, v := range s {
		err := n.InsertToTail(v)
		if err != nil {
			return nil, err
		}
	}
	return n, nil
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

// node must in the list
func (s *SingleLinkedList) InsertAfter(n *node, v interface{}) error {
	if n == nil {
		return errors.New("node can't be nil")
	}

	newNode := NewNode(v)
	newNode.next = n.next
	n.next = newNode
	s.length++
	return nil
}

// node must in the list
func (s *SingleLinkedList) InsertBefore(n *node, v interface{}) error {
	if n == nil {
		return errors.New("node can't be nil")
	}
	// can't insert before head node
	if n == s.head {
		return errors.New("can't insert before head")
	}

	pre := s.head
	for pre.next != n {
		pre = pre.next
	}

	newNode := NewNode(v)
	newNode.next = pre.next
	pre.next = newNode
	s.length++
	return nil
}

func (s *SingleLinkedList) InsertToHead(v interface{}) error {
	return s.InsertAfter(s.head, v)
}

func (s *SingleLinkedList) InsertToTail(v interface{}) error {
	cur := s.head
	// cur.next != nil
	// 1. prevent traversing a nil list
	// 2. traversing list
	for cur.next != nil {
		cur = cur.next
	}
	return s.InsertAfter(cur, v)
}

func (s *SingleLinkedList) Delete(n *node) error {
	if n == nil {
		return errors.New("node can't be nil")
	}
	if n == s.head {
		return errors.New("node can't be head node")
	}

	pre := s.head
	for pre.next != n {
		pre = pre.next
	}

	pre.next = n.next
	n = nil
	s.length--
	return nil
}

func (s *SingleLinkedList) Reverse() {
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

func (s SingleLinkedList) Last() (*node, error) {
	if s.head.next == nil {
		return nil, errors.New("list can't be have 0 node")
	}

	last := s.head
	for last.next != nil {
		last = last.next
	}
	return last, nil
}

// got first effective node when index = 0
func (s *SingleLinkedList) FindByIndex(index int) (*node, error) {
	if index < 0 || index >= s.length {
		return nil, errors.New("index can't be < 0 or >= s.length")
	}

	cur := s.head.next
	for i := 0; i < index; i++ {
		cur = cur.next
	}
	return cur, nil
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
