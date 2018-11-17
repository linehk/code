package linkedListStack

type stack struct {
	top *node
}

type node struct {
	value interface{}
	next  *node
}

func New() *stack {
	s := new(stack)
	return s
}

func (s *stack) Push(v interface{}) {
	n := new(node)
	n.value = v

	// empty stack wouldn't execute this
	// n.next will be nil
	if s.top != nil {
		n.next = s.top
	}
	s.top = n
}

func (s *stack) Pop() interface{} {
	if s.top == nil {
		return nil
	}

	v := s.top.value
	s.top = s.top.next
	return v
}
