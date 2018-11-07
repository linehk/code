package singleLinkedList

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
	s, _ := InitSingleLinkedList(elts)

	want := s.head.next
	got := s.head.GetNext()
	if got != want {
		t.Errorf("want %v, got %v\n", want, got)
	}
}

func TestNewSingleLinkedList(t *testing.T) {
	s := NewSingleLinkedList()
	wantHead := &node{nil, nil}
	wantLength := 0
	gotHead := s.head
	gotLength := s.length
	if gotHead.value != wantHead.value || gotHead.next != wantHead.next {
		t.Errorf("wantHead.value = %v, gotHead.value = %v\n", wantHead.value, gotHead.value)
		t.Errorf("wantHead.next = %v, gotHead.next = %v\n", wantHead.next, gotHead.next)
	}
	if gotLength != wantLength {
		t.Errorf("wantLength = %v, gotLength = %v\n", wantLength, gotLength)
	}
}

func TestInitSingleLinkedList(t *testing.T) {
	elts := []interface{}{1, 'a', "aa"}

	// normal slice
	s, _ := InitSingleLinkedList(elts)
	want := elts
	got := s.ToSlice()
	if !utils.IsSameSlice(got, want) {
		t.Errorf("want %v, got %v\n", want, got)
	}

	// nil slice
	elts = nil
	s, _ = InitSingleLinkedList(elts)
	want = []interface{}{}
	got = s.ToSlice()
	if !utils.IsSameSlice(got, want) {
		t.Errorf("want %v, got %v\n", want, got)
	}
}

func TestSingleLinkedList_ToSlice(t *testing.T) {
	elts := []interface{}{1, 'a', "aa"}

	// normal list
	s, _ := InitSingleLinkedList(elts)
	want := elts
	got := s.ToSlice()
	if !utils.IsSameSlice(got, want) {
		t.Errorf("want %v, got %v\n", want, got)
	}

	// nil list
	s = NewSingleLinkedList()
	want = []interface{}{}
	got = s.ToSlice()
	if !utils.IsSameSlice(got, want) {
		t.Errorf("want %v, got %v\n", want, got)
	}
}

func TestSingleLinkedList_InsertAfter(t *testing.T) {
	elts := []interface{}{1, 'a', "aa"}
	s, _ := InitSingleLinkedList(elts)

	// normal node
	v := 2
	s.InsertAfter(s.head.next, v)
	want := []interface{}{1, v, 'a', "aa"}
	got := s.ToSlice()
	if !utils.IsSameSlice(got, want) {
		t.Errorf("want %v, got %v\n", want, got)
	}

	// nil node
	err := s.InsertAfter(nil, v)
	if err == nil {
		t.Errorf("err shouldn't be nil, when node is nil\n")
	}
}

func TestSingleLinkedList_InsertBefore(t *testing.T) {
	elts := []interface{}{1, 'a', "aa"}
	s, _ := InitSingleLinkedList(elts)

	// normal node
	v := 2
	s.InsertBefore(s.head.next.next, v)
	want := []interface{}{1, v, 'a', "aa"}
	got := s.ToSlice()
	if !utils.IsSameSlice(got, want) {
		t.Errorf("want %v, got %v\n", want, got)
	}

	// nil node
	err := s.InsertBefore(nil, v)
	if err == nil {
		t.Errorf("err shouldn't be nil, when node is nil\n")
	}

	// head node
	err = s.InsertBefore(s.head, v)
	if err == nil {
		t.Errorf("err shouldn't be nil, when node is head node\n")
	}
}

func TestSingleLinkedList_InsertToHead(t *testing.T) {
	elts := []interface{}{1, 'a', "aa"}
	s, _ := InitSingleLinkedList(elts)

	v := 2
	s.InsertToHead(v)
	want := []interface{}{v, 1, 'a', "aa"}
	got := s.ToSlice()
	if !utils.IsSameSlice(got, want) {
		t.Errorf("want %v, got %v\n", want, got)
	}
}

func TestSingleLinkedList_InsertToTail(t *testing.T) {
	elts := []interface{}{1, 'a', "aa"}
	s, _ := InitSingleLinkedList(elts)

	v := 2
	s.InsertToTail(v)
	want := []interface{}{1, 'a', "aa", v}
	got := s.ToSlice()
	if !utils.IsSameSlice(got, want) {
		t.Errorf("want %v, got %v\n", want, got)
	}
}

func TestSingleLinkedList_Delete(t *testing.T) {
	elts := []interface{}{1, 'a', "aa"}
	s, _ := InitSingleLinkedList(elts)

	// normal node
	s.Delete(s.head.next)
	want := []interface{}{'a', "aa"}
	got := s.ToSlice()
	if !utils.IsSameSlice(got, want) {
		t.Errorf("want %v, got %v\n", want, got)
	}

	// nil node
	err := s.Delete(nil)
	if err == nil {
		t.Errorf("err shouldn't be nil, when node is nil\n")
	}

	// head node
	err = s.Delete(s.head)
	if err == nil {
		t.Errorf("err shouldn't be nil, when node is head node\n")
	}
}

func TestSingleLinkedList_Reverse(t *testing.T) {
	// normal list
	elts := []interface{}{1, 'a', "aa"}
	s, _ := InitSingleLinkedList(elts)
	s.Reverse()
	want := []interface{}{"aa", 'a', 1}
	got := s.ToSlice()
	if !utils.IsSameSlice(got, want) {
		t.Errorf("want %v, got %v\n", want, got)
	}

	// 2 node
	elts = []interface{}{1, 'a'}
	s, _ = InitSingleLinkedList(elts)
	s.Reverse()
	want = []interface{}{'a', 1}
	got = s.ToSlice()
	if !utils.IsSameSlice(got, want) {
		t.Errorf("want %v, got %v\n", want, got)
	}

	// 1 node
	elts = []interface{}{1}
	s, _ = InitSingleLinkedList(elts)
	s.Reverse()
	want = elts
	got = s.ToSlice()
	if !utils.IsSameSlice(got, want) {
		t.Errorf("want %v, got %v\n", want, got)
	}
}

func TestSingleLinkedList_Last(t *testing.T) {
	// normal list
	v := "aa"
	elts := []interface{}{1, 'a', v}
	s, _ := InitSingleLinkedList(elts)
	wantNode := NewNode(v)
	wantValue := wantNode.value
	wantNext := wantNode.next
	gotNode, _ := s.Last()
	gotValue := gotNode.value
	gotNext := gotNode.next
	if gotValue != wantValue || gotNext != wantNext {
		t.Errorf("wantValue = %v, gotValue = %v\n", wantValue, gotValue)
		t.Errorf("wantNext = %v, gotNext = %v\n", wantNext, gotNext)
	}

	// zero-node list
	s = NewSingleLinkedList()
	_, err := s.Last()
	if err == nil {
		t.Errorf("err shouldn't be nil, when get the last node on a zero-node list")
	}
}

func TestSingleLinkedList_FindByIndex(t *testing.T) {
	elts := []interface{}{1, 'a', "aa"}
	s, _ := InitSingleLinkedList(elts)

	// normal index
	wantNode := s.head.next
	wantValue := wantNode.value
	wantNext := wantNode.next
	gotNode, _ := s.FindByIndex(0)
	gotValue := gotNode.value
	gotNext := gotNode.next
	if gotValue != wantValue || gotNext != wantNext {
		t.Errorf("wantValue = %v, gotValue = %v\n", wantValue, gotValue)
		t.Errorf("wantNext = %v, gotNext = %v\n", wantNext, gotNext)
	}

	// illegal index (-1, len(elts), len(elts)+1)
	if _, err := s.FindByIndex(-1); err == nil {
		t.Errorf("err shouldn't be nil, when index = -1\n")
	}
	if _, err := s.FindByIndex(len(elts)); err == nil {
		t.Errorf("err shouldn't be nil, when index = len(elts)\n")
	}
	if _, err := s.FindByIndex(len(elts) + 1); err == nil {
		t.Errorf("err shouldn't be nil, when index = len(elts)+1\n")
	}
}

func TestSingleLinkedList_Show(t *testing.T) {
	elts := []interface{}{1, 'a', "aa"}
	s, _ := InitSingleLinkedList(elts)

	want := fmt.Sprintf("%v->%v->%v", 1, 'a', "aa")
	got := s.Show()
	if got != want {
		t.Errorf("want %v, got %v\n", want, got)
	}
}
