package arrayStack

type stack struct {
	cap      int
	top      int
	elements []interface{}
}

func New(cap int) *stack {
	s := new(stack)
	s.cap = cap
	s.top = -1
	s.elements = make([]interface{}, s.cap)
	return s
}

func (s *stack) Push(v interface{}) {
	if s.top+1 >= s.cap {
		return
	}

	s.elements[s.top+1] = v
	s.top++
}

func (s *stack) Pop() interface{} {
	if s.top < 0 {
		return nil
	}

	v := s.elements[s.top]
	s.elements[s.top] = nil
	s.top--
	return v
}
