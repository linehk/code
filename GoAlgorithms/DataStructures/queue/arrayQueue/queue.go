package arrayQueue

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
	if q.rear == q.cap {
		return
	}
	q.elements[q.rear] = v
	q.rear++
	q.len++
}

func (q *queue) Dequeue() interface{} {
	if q.front == q.rear {
		return nil
	}
	v := q.elements[q.front]
	q.elements[q.front] = nil
	q.front++
	q.len--
	return v
}
