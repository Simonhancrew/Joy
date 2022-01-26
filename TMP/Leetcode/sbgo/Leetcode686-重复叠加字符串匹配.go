package sbgo

import "strings"

func repeatedStringMatch(a string, b string) int {
	s, i := a, 1
	for len(s) < len(b) {
		s += a
		i++
	}
	if strings.Contains(s, b) {
		return i
	} else {
		s += a
		i++
		if strings.Contains(s, b) {
			return i
		}
	}
	return -1
}
