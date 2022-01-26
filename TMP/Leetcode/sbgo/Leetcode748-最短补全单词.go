package sbgo

import "unicode"

func shortestCompletingWord(licensePlate string, words []string) string {
	mp := [26]int{}
	for _, ch := range licensePlate {
		if unicode.IsLetter(ch) {
			mp[unicode.ToLower(ch)-'a']++
		}
	}
	idx := -1
	for i := 0; i < len(words); i++ {
		c := [26]int{}
		for j := 0; j < len(words[i]); j++ {
			c[words[i][j]-'a']++
		}
		ok := true
		for j := 0; j < 26; j++ {
			if mp[j] > c[j] {
				ok = false
				break
			}
		}
		if ok && (idx < 0 || len(words[idx]) > len(words[i])) {
			idx = i
		}
	}
	return words[idx]
}
