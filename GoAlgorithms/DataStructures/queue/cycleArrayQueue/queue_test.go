package cycleArrayQueue

import (
	"testing"
)

func TestQueue(t *testing.T) {
	q := New(4)
	q.Enqueue(1)
	q.Enqueue(2)
	q.Enqueue(3)
	q.Enqueue(4)

	t.Log(q.Dequeue())
	t.Log(q.Dequeue())
	t.Log(q.Dequeue())
	t.Log(q.Dequeue())

	q.Enqueue(1)
	q.Enqueue(2)
	q.Enqueue(3)
	q.Enqueue(4)

	t.Log(q.Dequeue())
	t.Log(q.Dequeue())
	t.Log(q.Dequeue())
	t.Log(q.Dequeue())

	q.Enqueue(1)
	q.Enqueue(2)
	q.Enqueue(3)
	q.Enqueue(4)

	t.Log(q.Dequeue())
	t.Log(q.Dequeue())
	t.Log(q.Dequeue())
	t.Log(q.Dequeue())
}
