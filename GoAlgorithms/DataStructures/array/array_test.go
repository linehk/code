package array

import (
	"testing"

	"GoAlgorithms/utils"
)

func TestGet(t *testing.T) {
	a := New(1)
	index := 0
	want := 0
	a.elements[index] = want
	a.len++
	got, err := a.Get(index)
	if err != nil {
		t.Error(err)
	}
	if got != want {
		t.Errorf("got %v, want %v", got, want)
	}
}

func TestAppend(t *testing.T) {
	a := New(4)
	want := []interface{}{0, 1, 2, 3}
	for _, v := range want {
		a.Append(v)
	}
	got := a.elements
	if !utils.IsSameSlice(got, want) {
		t.Errorf("want %v, got %v", want, got)
	}
}

func TestInsert(t *testing.T) {
	a := New(4)
	value := 2
	slice := []interface{}{0, 1, 3}
	want := []interface{}{0, 1, value, 3}
	for _, v := range slice {
		a.Append(v)
	}
	err := a.Insert(2, value)
	if err != nil {
		t.Error(err)
	}
	got := a.elements
	if !utils.IsSameSlice(got, want) {
		t.Errorf("want %v, got %v", want, got)
	}
}

func TestDelete(t *testing.T) {
	a := New(4)
	slice := []interface{}{0, 1, 2, 3}
	want := []interface{}{0, 1, 3, nil}
	for _, v := range slice {
		a.Append(v)
	}
	err := a.Delete(2)
	if err != nil {
		t.Error(err)
	}
	got := a.elements
	if !utils.IsSameSlice(got, want) {
		t.Errorf("want %v, got %v", want, got)
	}
}

func TestRemove(t *testing.T) {
	a := New(4)
	value := 1
	slice := []interface{}{0, 0, value, value}
	want := []interface{}{0, 0, nil, nil}
	for _, v := range slice {
		a.Append(v)
	}
	err := a.Remove(value)
	if err != nil {
		t.Error(err)
	}
	got := a.elements
	if !utils.IsSameSlice(got, want) {
		t.Errorf("want %v, got %v", want, got)
	}
}

func TestFind(t *testing.T) {
	a := New(4)
	value := 1
	slice := []interface{}{0, 0, value, value}
	want := value
	for _, v := range slice {
		a.Append(v)
	}
	i, err := a.Find(value)
	if err != nil {
		t.Error(err)
	}
	got := a.elements[i]
	if got != want {
		t.Errorf("want %v, got %v", want, got)
	}
}

func TestResize(t *testing.T) {
	a := New(1)
	want := cap(a.elements) * 2
	a.resize(a.cap * 2)
	got := cap(a.elements)
	if got != want {
		t.Errorf("want %v, got %v", want, got)
	}
}
