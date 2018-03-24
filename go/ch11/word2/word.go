package word

import "unicode"

func IsPalindrome(s string) bool {
	// 221 ns/op
	letters := make([]rune, 0, len(s))
	for _, r := range s {
		if unicode.IsLetter(r) {
			letters = append(letters, unicode.ToLower(r))
		}
	}
	/*
		var letters []rune
		for _, r := range s {
			if unicode.IsLetter(r) {
				letters = append(letters, unicode.ToLower(r))
			}
		}
	*/

	/* 435 ns/op
	for i := range letters {
		if letters[i] != letters[len(letters)-1-i] {
			return false
		}
	}
	return true
	*/

	// 420 ns/op
	n := len(letters) / 2
	for i := 0; i < n; i++ {
		if letters[i] != letters[len(letters)-1-i] {
			return false
		}
	}
	return true
}
