package singleLinkedList

import (
        "testing"
)

func TestSingleLinkedList_Reverse(t *testing.T) {
}

func TestInitSingleLinkedList(t *testing.T) {
}

func TestSingleLinkedList_FindByIndex(t *testing.T) {
        array := []int{1, 2, 3}
        s := InitSingleLinkedList(array)
        t.Log(s.FindByIndex(1).GetValue())
}

func TestSingleLinkedList_Delete(t *testing.T) {
        array := []int{1, 2, 3}
        s := InitSingleLinkedList(array)
        ok := s.Delete(NewNode(1))
        t.Log(ok)
}