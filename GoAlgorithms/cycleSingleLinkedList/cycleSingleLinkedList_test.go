package cycleSingleLinkedList

import (
	"GoAlgorithms/utils"
	"fmt"
	"testing"
)

func TestNewNode(t *testing.T) {
	v := 1

	wantValue := v
	var wantNext *node // nil
	gotNode := NewNode(v)
	gotValue := gotNode.value
	gotNext := gotNode.next
	if gotValue != wantValue || gotNext != wantNext {
		t.Errorf("wantValue = %v, gotValue = %v\n", wantValue, gotValue)
		t.Errorf("wantNext = %v, gotNext = %v\n", wantNext, gotNext)
	}
}

func TestNode_GetValue(t *testing.T) {
	v := 1

	want := v
	got := NewNode(v).GetValue()
	if got != want {
		t.Errorf("want %v, got %v\n", want, got)
	}
}

func TestNode_GetNext(t *testing.T) {
	elts := []interface{}{1, 'a', "aa"}
	c, _ := InitCycleSingleLinkedList(elts)

	want := c.head.next
	got := c.head.GetNext()
	if got != want {
		t.Errorf("want %v, got %v\n", want, got)
	}
}

func TestNewCycleSingleLinkedList(t *testing.T) {
	c := NewCycleSingleLinkedList()
	wantHead := &node{nil, nil}
	wantLength := 0
	gotHead := c.head
	gotLength := c.length
	if gotHead.value != wantHead.value || gotHead.next != wantHead.next {
		t.Errorf("wantHead.value = %v, gotHead.value = %v\n", wantHead.value, gotHead.value)
		t.Errorf("wantHead.next = %v, gotHead.next = %v\n", wantHead.next, gotHead.next)
	}
	if gotLength != wantLength {
		t.Errorf("wantLength = %v, gotLength = %v\n", wantLength, gotLength)
	}
}

func TestInitCycleSingleLinkedList(t *testing.T) {
	elts := []interface{}{1, 'a', "aa"}

	// normal slice
	c, _ := InitCycleSingleLinkedList(elts)
	want := elts
	got := c.ToSlice()
	if !utils.IsSameSlice(got, want) {
		t.Errorf("want %v, got %v\n", want, got)
	}

	// nil slice
	elts = nil
	c, _ = InitCycleSingleLinkedList(elts)
	want = []interface{}{}
	got = c.ToSlice()
	if !utils.IsSameSlice(got, want) {
		t.Errorf("want %v, got %v\n", want, got)
	}
}

func TestCycleSingleLinkedList_ToSlice(t *testing.T) {
	elts := []interface{}{1, 'a', "aa"}

	// normal list
	c, _ := InitCycleSingleLinkedList(elts)
	want := elts
	got := c.ToSlice()
	if !utils.IsSameSlice(got, want) {
		t.Errorf("want %v, got %v\n", want, got)
	}

	// nil list
	c = NewCycleSingleLinkedList()
	want = []interface{}{}
	got = c.ToSlice()
	if !utils.IsSameSlice(got, want) {
		t.Errorf("want %v, got %v\n", want, got)
	}
}

func TestCycleSingleLinkedList_InsertAfter(t *testing.T) {
	elts := []interface{}{1, 'a', "aa"}
	c, _ := InitCycleSingleLinkedList(elts)

	// normal node
	v := 2
	c.InsertAfter(c.head.next, v)
	want := []interface{}{1, v, 'a', "aa"}
	got := c.ToSlice()
	if !utils.IsSameSlice(got, want) {
		t.Errorf("want %v, got %v\n", want, got)
	}

	// nil node
	err := c.InsertAfter(nil, v)
	if err == nil {
		t.Errorf("err shouldn't be nil, when node is nil\n")
	}
}

func TestCycleSingleLinkedList_InsertBefore(t *testing.T) {
	elts := []interface{}{1, 'a', "aa"}
	c, _ := InitCycleSingleLinkedList(elts)

	// normal node
	v := 2
	c.InsertBefore(c.head.next.next, v)
	want := []interface{}{1, v, 'a', "aa"}
	got := c.ToSlice()
	if !utils.IsSameSlice(got, want) {
		t.Errorf("want %v, got %v\n", want, got)
	}

	// nil node
	err := c.InsertBefore(nil, v)
	if err == nil {
		t.Errorf("err shouldn't be nil, when node is nil\n")
	}

	// head node
	err = c.InsertBefore(c.head, v)
	if err == nil {
		t.Errorf("err shouldn't be nil, when node is head node\n")
	}
}

func TestCycleSingleLinkedList_InsertToHead(t *testing.T) {
	elts := []interface{}{1, 'a', "aa"}
	c, _ := InitCycleSingleLinkedList(elts)

	v := 2
	c.InsertToHead(v)
	want := []interface{}{v, 1, 'a', "aa"}
	got := c.ToSlice()
	if !utils.IsSameSlice(got, want) {
		t.Errorf("want %v, got %v\n", want, got)
	}
}

func TestCycleSingleLinkedList_InsertToTail(t *testing.T) {
	elts := []interface{}{1, 'a', "aa"}
	c, _ := InitCycleSingleLinkedList(elts)

	v := 2
	c.InsertToTail(v)
	want := []interface{}{1, 'a', "aa", v}
	got := c.ToSlice()
	if !utils.IsSameSlice(got, want) {
		t.Errorf("want %v, got %v\n", want, got)
	}
}

func TestCycleSingleLinkedList_Delete(t *testing.T) {
	elts := []interface{}{1, 'a', "aa"}
	c, _ := InitCycleSingleLinkedList(elts)

	// normal node
	c.Delete(c.head.next)
	want := []interface{}{'a', "aa"}
	got := c.ToSlice()
	if !utils.IsSameSlice(got, want) {
		t.Errorf("want %v, got %v\n", want, got)
	}

	// nil node
	err := c.Delete(nil)
	if err == nil {
		t.Errorf("err shouldn't be nil, when node is nil\n")
	}

	// head node
	err = c.Delete(c.head)
	if err == nil {
		t.Errorf("err shouldn't be nil, when node is head node\n")
	}
}

func TestCycleSingleLinkedList_Reverse(t *testing.T) {
	// normal list
	elts := []interface{}{1, 'a', "aa"}
	c, _ := InitCycleSingleLinkedList(elts)
	c.Reverse()
	want := []interface{}{"aa", 'a', 1}
	got := c.ToSlice()
	if !utils.IsSameSlice(got, want) {
		t.Errorf("want %v, got %v\n", want, got)
	}

	// 2 node
	elts = []interface{}{1, 'a'}
	c, _ = InitCycleSingleLinkedList(elts)
	c.Reverse()
	want = []interface{}{'a', 1}
	got = c.ToSlice()
	if !utils.IsSameSlice(got, want) {
		t.Errorf("want %v, got %v\n", want, got)
	}

	// 1 node
	elts = []interface{}{1}
	c, _ = InitCycleSingleLinkedList(elts)
	c.Reverse()
	want = elts
	got = c.ToSlice()
	if !utils.IsSameSlice(got, want) {
		t.Errorf("want %v, got %v\n", want, got)
	}
}

func TestCycleSingleLinkedList_Last(t *testing.T) {
	// normal list
	v := "aa"
	elts := []interface{}{1, 'a', v}
	c, _ := InitCycleSingleLinkedList(elts)
	wantValue := v
	wantNext := c.head
	last, _ := c.Last()
	gotValue := last.value
	gotNext := last.next
	if gotValue != wantValue || gotNext != wantNext {
		t.Errorf("wantValue = %v, gotValue = %v\n", wantValue, gotValue)
		t.Errorf("wantNext = %v, gotNext = %v\n", wantNext, gotNext)
	}

	// zero-node list
	c = NewCycleSingleLinkedList()
	_, err := c.Last()
	if err == nil {
		t.Errorf("err shouldn't be nil, when get the last node on a zero-node list")
	}
}

func TestCycleSingleLinkedList_FindByIndex(t *testing.T) {
	elts := []interface{}{1, 'a', "aa"}
	c, _ := InitCycleSingleLinkedList(elts)

	// normal index
	wantNode := c.head.next
	wantValue := wantNode.value
	wantNext := wantNode.next
	gotNode, _ := c.FindByIndex(0)
	gotValue := gotNode.value
	gotNext := gotNode.next
	if gotValue != wantValue || gotNext != wantNext {
		t.Errorf("wantValue = %v, gotValue = %v\n", wantValue, gotValue)
		t.Errorf("wantNext = %v, gotNext = %v\n", wantNext, gotNext)
	}

	// illegal index (-1, len(elts), len(elts)+1)
	if _, err := c.FindByIndex(-1); err == nil {
		t.Errorf("err shouldn't be nil, when index = -1\n")
	}
	if _, err := c.FindByIndex(len(elts)); err == nil {
		t.Errorf("err shouldn't be nil, when index = len(elts)\n")
	}
	if _, err := c.FindByIndex(len(elts) + 1); err == nil {
		t.Errorf("err shouldn't be nil, when index = len(elts)+1\n")
	}
}

func TestCycleSingleLinkedList_Show(t *testing.T) {
	elts := []interface{}{1, 'a', "aa"}
	c, _ := InitCycleSingleLinkedList(elts)

	want := fmt.Sprintf("%v->%v->%v", 1, 'a', "aa")
	got := c.Show()
	if got != want {
		t.Errorf("want %v, got %v\n", want, got)
	}
}
