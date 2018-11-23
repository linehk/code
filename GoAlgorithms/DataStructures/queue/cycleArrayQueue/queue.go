package cycleArrayQueue

type queue struct {
	cap      int
	len      int
	front    int
	rear     int
	elements []interface{}
}

func New(cap int) *queue {
	q := new(queue)
	q.cap = cap
	q.len = 0
	q.front = 0
	q.rear = 0
	q.elements = make([]interface{}, q.cap)
	return q
}

func (q *queue) Enqueue(v interface{}) {
	if (q.rear+1)%q.cap == q.front {
		return
	}
	q.elements[q.rear] = v
	q.rear = (q.rear + 1) % q.cap
	q.len++
}

func (q *queue) Dequeue() interface{} {
	if q.front == q.rear {
		return nil
	}
	v := q.elements[q.front]
	q.elements[q.front] = nil
	q.front = (q.front + 1) % q.cap
	q.len--
	return v
}
