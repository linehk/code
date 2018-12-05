package arrayQueue

import (
	"testing"
)

func TestQueue(t *testing.T) {
	seq := []interface{}{0, 1, 2, 3}
	q := New(len(seq))

	for _, v := range seq {
		if err := q.Enqueue(v); err != nil {
			t.Error(err)
		}
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
