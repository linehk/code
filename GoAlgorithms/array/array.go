package array

type array struct {
	len      int // available element numbers
	cap      int
	elements []interface{}
}

func New(cap int) *array {
	a := new(array)
	a.len = 0
	a.cap = cap
	a.elements = make([]interface{}, a.cap)
	return a
}

func (a array) Get(i int) interface{} {
	if i < 0 || i >= a.len {
		return nil
	}

	return a.elements[i]
}

func (a *array) Set(i int, v interface{}) {
	if i < 0 || i >= a.len {
		return
	}

	a.elements[i] = v
}

// Insert v at index i
func (a *array) Insert(i int, v interface{}) {
	if i < 0 || i >= a.cap {
		return
	}

	if a.len+1 > a.cap {
		return
	}

	for lastIndex := a.len - 1; lastIndex >= i; lastIndex-- {
		a.elements[lastIndex+1] = a.elements[lastIndex]
	}

	a.elements[i] = v
	a.len++
}

// Delete element in i
func (a *array) Delete(i int) {
	if i < 0 || i >= a.len {
		return
	}

	for ; i < a.len-1; i++ {
		a.elements[i] = a.elements[i+1]
	}

	a.elements[a.len-1] = nil
	a.len--
}
