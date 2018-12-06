package evaluate

import (
	"testing"
)

func TestEval(t *testing.T) {
	tests := []struct {
		s    string
		want int32
	}{
		{"(1+1)", 2},
	}
	for i, tt := range tests {
		if got := eval(tt.s); got != tt.want {
			t.Errorf("%v. got %v, want %v", i, got, tt.want)
		}
	}
}

func TestByte(t *testing.T)  {
        s := "(1+1)"
        for _, ch := range s {
                t.Log(ch-'0')
        }
}
