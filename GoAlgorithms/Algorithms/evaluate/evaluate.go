// Package evaluate implements arithmetic expression by Dijkstra double stack.
package evaluate

import (
	"GoAlgorithms/DataStructures/stack/linkedListStack"
)

func eval(s string) int32 {
	ops := linkedListStack.New()
	vals := linkedListStack.New()

	for _, ch := range s {
		switch ch {
		case '(':
		        break
		case '+':
			ops.Push(ch)
		case '-':
			ops.Push(ch)
		case '*':
			ops.Push(ch)
		case '/':
			ops.Push(ch)
		case ')':
			op, _ := ops.Pop()
			o, _ := op.(int32)
                        val, _ := vals.Pop()
                        v, _ := val.(int32)
                        v -= '0'
			switch o {
			case '+':
				tmp, _ := vals.Pop()
				t, _ := tmp.(int32)
				t -= '0'
				v += t
			case '-':
				tmp, _ := vals.Pop()
				t, _ := tmp.(int32)
                                t -= '0'
				v -= t
			case '*':
				tmp, _ := vals.Pop()
				t, _ := tmp.(int32)
                                t -= '0'
				v *= t
			case '/':
				tmp, _ := vals.Pop()
				t, _ := tmp.(int32)
                                t -= '0'
				v /= t
			}
                        vals.Push(v)
		default:
			vals.Push(int32(ch))
		}
	}
	val, _ := vals.Pop()
	v, _ := val.(int32)
	return v
}
