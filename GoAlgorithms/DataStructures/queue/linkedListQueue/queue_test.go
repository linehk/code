package linkedListQueue

import (
	"testing"
)

func TestQueue(t *testing.T) {
	seq := []interface{}{0, 1, 2, 3}
	q := New()

	for _, v := range seq {
		q.Enqueue(v)
	}

	for _, v := range seq {
		got, err := q.Dequeue()
		if err != nil {
			t.Error(err)
		}
		if got != v {
			t.Errorf("got %v, want %v", got, v)
		}
	}
}
