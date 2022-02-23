package sbgo

import "unicode"

func reverseOnlyLetters(s string) string {
	n := len(s)
	ss := []byte(s)
	for i, j := 0, n-1; i < j; i, j = i+1, j-1 {
		for i < j && !unicode.IsLetter(rune(ss[i])) {
			i++
		}
		for i < j && !unicode.IsLetter(rune(ss[j])) {
			j--
		}
		ss[i], ss[j] = ss[j], ss[i]
	}
	return string(ss)
}
