package sbgo

import "strings"

func isPrefixOfWord(sentence string, searchWord string) int {
	rec, ans, idx := strings.Split(sentence, " "), -1, 0
	check := func(s, p string) bool {
		if len(p) > len(s) {
			return false
		}
		for i := 0; i < len(p); i++ {
			if s[i] != p[i] {
				return false
			}
		}
		return true
	}
	for _, s := range rec {
		idx++
		if check(s, searchWord) {
			ans = idx
			break
		}
	}
	return ans
}
