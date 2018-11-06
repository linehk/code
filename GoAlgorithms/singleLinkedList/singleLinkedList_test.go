package singleLinkedList

import (
        "GoAlgorithms/utils"
        "fmt"
        "testing"
)

func TestNewNode(t *testing.T) {
        elt := []interface{}{1, 'a', "aa"}
        got := make([]interface{}, len(elt))
        for i, v := range elt {
                got[i] = NewNode(v).GetValue()
        }
        if !utils.IsSameSlice(got, elt) {
                t.Errorf("want %v, got %v\n", elt, got)
        }
}

func TestNewSingleLinkedList(t *testing.T) {
        s := NewSingleLinkedList()
        wantLength := 0
        if s.head.value != nil {
                t.Errorf("want %v, got %v\n", nil, s.head.value)
        }
        if s.length != wantLength {
                t.Errorf("want %d, got %d\n", wantLength, s.length)
        }
}

func TestInitSingleLinkedList(t *testing.T) {
        elt := []interface{}{1, 'a', "aa"}
        n := InitSingleLinkedList(elt)
        got := n.ToSlice()
        if !utils.IsSameSlice(got, elt) {
                t.Errorf("want %v, got %v\n", elt, got)
        }

        // nil slice
        elt = nil
        n = InitSingleLinkedList(elt)
        want := []interface{}{}
        got = n.ToSlice()
        if !utils.IsSameSlice(got, want) {
                t.Errorf("want %v, got %v\n", want, got)
        }
}

func TestSingleLinkedList_ToSlice(t *testing.T) {
        elt := []interface{}{1, 'a', "aa"}
        n := InitSingleLinkedList(elt)
        got := n.ToSlice()
        if !utils.IsSameSlice(got, elt) {
                t.Errorf("want %v, got %v\n", elt, got)
        }
}

func TestNode_GetValue(t *testing.T) {
        want := 0
        n := NewNode(want)
        got := n.GetValue()
        if got != want {
                t.Errorf("want %v, got %v\n", want, got)
        }
}

func TestNode_GetNext(t *testing.T) {
        elt := []interface{}{1, 'a', "aa"}
        n := InitSingleLinkedList(elt)
        want := 1
        got := n.head.GetNext().GetValue()
        if got != want {
                t.Errorf("want %v, got %v\n", want, got)
        }
}

func TestSingleLinkedList_InsertAfter(t *testing.T) {
        elt := []interface{}{1, 'a', "aa"}
        n := InitSingleLinkedList(elt)
        v := 2
        want := []interface{}{1, v, 'a', "aa"}
        n.InsertAfter(n.head.next, v)
        got := n.ToSlice()
        if !utils.IsSameSlice(got, want) {
                t.Errorf("want %v, got %v\n", want, got)
        }
}

func TestSingleLinkedList_InsertBefore(t *testing.T) {
        elt := []interface{}{1, 'a', "aa"}
        n := InitSingleLinkedList(elt)
        v := 2
        want := []interface{}{1, v, 'a', "aa"}
        n.InsertBefore(n.head.next.next, v)
        got := n.ToSlice()
        if !utils.IsSameSlice(got, want) {
                t.Errorf("want %v, got %v\n", want, got)
        }
}

func TestSingleLinkedList_InsertToHead(t *testing.T) {
        elt := []interface{}{1, 'a', "aa"}
        n := InitSingleLinkedList(elt)
        v := 2
        want := []interface{}{v, 1, 'a', "aa"}
        n.InsertToHead(v)
        got := n.ToSlice()
        if !utils.IsSameSlice(got, want) {
                t.Errorf("want %v, got %v\n", want, got)
        }
}

func TestSingleLinkedList_InsertToTail(t *testing.T) {
        elt := []interface{}{1, 'a', "aa"}
        n := InitSingleLinkedList(elt)
        v := 2
        want := []interface{}{1, 'a', "aa", v}
        n.InsertToTail(v)
        got := n.ToSlice()
        if !utils.IsSameSlice(got, want) {
                t.Errorf("want %v, got %v\n", want, got)
        }
}

func TestSingleLinkedList_FindByIndex(t *testing.T) {
        elt := []interface{}{1, 'a', "aa"}
        n := InitSingleLinkedList(elt)
        got := make([]interface{}, len(elt))
        for i := range elt {
                node, err := n.FindByIndex(i)
                if err != nil {
                        t.Errorf("err: %s\n", err)
                }
                got[i] = node.GetValue()
        }
        if !utils.IsSameSlice(got, elt) {
                t.Errorf("want %v, got %v\n", elt, got)
        }

        // illegal index
        if _, err := n.FindByIndex(-1); err == nil {
                t.Errorf("index < 0, err shouldn't be %v\n", err)
        }
        if _, err := n.FindByIndex(len(elt)); err == nil {
                t.Errorf("index == len, err shouldn't be %v\n", err)
        }
        if _, err := n.FindByIndex(len(elt) + 1); err == nil {
                t.Errorf("index > len, err shouldn't be %v\n", err)
        }
}

func TestSingleLinkedList_Delete(t *testing.T) {
        elt := []interface{}{1, 'a', "aa"}
        n := InitSingleLinkedList(elt)
        want := []interface{}{'a', "aa"}
        if n.Delete(n.head.next) {
                got := n.ToSlice()
                if !utils.IsSameSlice(got, want) {
                        t.Errorf("want %v, got %v\n", want, elt)
                }
        }
}

func TestSingleLinkedList_Show(t *testing.T) {
        elt := []interface{}{1, 'a', "aa"}
        got := InitSingleLinkedList(elt).Show()
        want := fmt.Sprintf("%v->%v->%v", 1, 'a', "aa")
        if got != want {
                t.Errorf("want %v, got %v\n", want, got)
        }
}

func TestSingleLinkedList_Reverse(t *testing.T) {
        elt := []interface{}{1, 'a', "aa"}
        n := InitSingleLinkedList(elt)
        n.Reverse()
        got := n.ToSlice()
        want := []interface{}{"aa", 'a', 1}
        if !utils.IsSameSlice(got, want) {
                t.Errorf("want %v, got %v\n", want, got)
        }
}