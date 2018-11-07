// CycleSingleLinkedList with head node
package cycleSingleLinkedList

import (
	"bytes"
	"errors"
	"fmt"
)

type node struct {
	value interface{}
	next  *node
}

type CycleSingleLinkedList struct {
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

func NewCycleSingleLinkedList() *CycleSingleLinkedList {
	return &CycleSingleLinkedList{0, NewNode(nil)}
}

func InitCycleSingleLinkedList(s []interface{}) (*CycleSingleLinkedList, error) {
	c := NewCycleSingleLinkedList()
	for _, v := range s {
		err := c.InsertToTail(v)
		if err != nil {
			return nil, err
		}
	}
	return c, nil
}

func (c CycleSingleLinkedList) ToSlice() []interface{} {
	slice := make([]interface{}, c.length)
	cur := c.head.next
	for i := range slice {
		slice[i] = cur.GetValue()
		cur = cur.next
	}
	return slice
}

// node must in the list
func (c *CycleSingleLinkedList) InsertAfter(n *node, v interface{}) error {
	if n == nil {
		return errors.New("node can't be nil")
	}

	newNode := NewNode(v)
	if n.next == nil {
		newNode.next = c.head
	} else {
		newNode.next = n.next
	}
	n.next = newNode
	c.length++
	return nil
}

// node must in the list
func (c *CycleSingleLinkedList) InsertBefore(n *node, v interface{}) error {
	if n == nil {
		return errors.New("node can't be nil")
	}
	// can't insert before head node
	if n == c.head {
		return errors.New("can't insert before head")
	}

	pre := n
	for pre.next != nil && pre.next != n {
		pre = pre.next
	}

	newNode := NewNode(v)
	newNode.next = pre.next
	pre.next = newNode
	c.length++
	return nil
}

func (c *CycleSingleLinkedList) InsertToHead(v interface{}) error {
	return c.InsertAfter(c.head, v)
}

func (c *CycleSingleLinkedList) InsertToTail(v interface{}) error {
	last := c.head
	// 1. prevent traversing a nil list
	// 2. traversing list
	for last.next != nil && last.next != c.head {
		last = last.next
	}
	return c.InsertAfter(last, v)
	// return c.InsertAfter(c.Last(), v)
}

func (c *CycleSingleLinkedList) Delete(n *node) error {
	if n == nil {
		return errors.New("node can't be nil")
	}
	if n == c.head {
		return errors.New("node can't be head node")
	}

	pre := n
	for pre.next != nil && pre.next != n {
		pre = pre.next
	}

	pre.next = n.next
	n = nil
	c.length--
	return nil
}

func (c *CycleSingleLinkedList) Reverse() {
	pre := c.head
	cur := c.head.next
	for cur != c.head {
		tmp := cur.next
		cur.next = pre
		pre = cur
		cur = tmp
	}
	c.head.next = pre
}

func (c CycleSingleLinkedList) Last() (*node, error) {
	if c.head.next == nil || c.head.next == c.head {
		return nil, errors.New("list can't be have 0 node")
	}

	last := c.head
	for last.next != nil && last.next != c.head {
		last = last.next
	}
	return last, nil
}

// got first effective node when index = 0
func (c CycleSingleLinkedList) FindByIndex(index int) (*node, error) {
	if index < 0 || index >= c.length {
		return nil, errors.New("index can't be < 0 or >= c.length")
	}

	cur := c.head.next
	for i := 0; i < index; i++ {
		cur = cur.next
	}
	return cur, nil
}

func (c CycleSingleLinkedList) Show() string {
	format := ""
	cur := c.head
	for cur.next != nil && cur.next != c.head {
		cur = cur.next
		format += fmt.Sprintf("%+v->", cur.GetValue())
	}
	format = string(bytes.TrimSuffix([]byte(format), []byte("->")))
	return format
}
