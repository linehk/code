package linkedListQueue

type node struct {
	value interface{}
	next  *node
}

type queue struct {
	len   int
	front *node
	rear  *node
}

func New() *queue {
	n := new(node)
	n.next = nil
	n.value = nil

	q := new(queue)
	q.len = 0
	q.front = n
	q.rear = n
	return q
}

func (q *queue) Enqueue(v interface{}) {
	q.rear.value = v
	n := new(node)
	n.value = nil
	n.next = nil
	q.rear.next = n
	q.rear = n
	q.len++
}

func (q *queue) Dequeue() interface{} {
	if q.front == q.rear {
		return nil
	}
	v := q.front.value
	q.front.value = nil
	next := q.front.next
	q.front.next = nil
	q.front = next
	q.len--
	return v
}
