package arrayQueue

import (
	"testing"
)

func TestQueue(t *testing.T) {
	q := New(3)
	q.Enqueue(1)
	q.Enqueue(2)
	q.Enqueue(3)
	t.Log(q)

	t.Log(q.Dequeue())
	t.Log(q)

	q.Enqueue(10)
	t.Log(q)
}
