package cycleArrayQueue

import (
	"testing"
)

func TestQueue(t *testing.T) {
	q := New(4)
	q.Enqueue(1)
	q.Enqueue(2)
	q.Enqueue(3)
	t.Log(q)

	// q.Enqueue(1)
	// t.Log(q)

	t.Log(q.Dequeue())
	t.Log(q.Dequeue())
	t.Log(q.Dequeue())
	t.Log(q)

	q.Enqueue(1)
	q.Enqueue(2)
	q.Enqueue(3)
	t.Log(q)

	t.Log(q.Dequeue())
	t.Log(q)

	q.Enqueue(1)
	q.Enqueue(2)
	q.Enqueue(3)
	t.Log(q)
}
