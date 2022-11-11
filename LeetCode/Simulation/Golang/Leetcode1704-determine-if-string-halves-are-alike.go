package sbgo

import "strings"

func halvesAreAlike(s string) bool {
	n, cnt := len(s)/2, 0
	for i := 0; i < n; i++ {
		if strings.ContainsRune("aeiouAEIOU", rune(s[i])) {
			cnt++
		}
	}
	for i := n; i < 2*n; i++ {
		if strings.ContainsRune("aeiouAEIOU", rune(s[i])) {
			cnt--
		}
		if cnt < 0 {
			return false
		}
	}
	return cnt == 0
}
