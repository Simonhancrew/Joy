package sbgo

import "strings"

func mergeAlternately(word1 string, word2 string) string {
	min := func(i, j int) int {
		if i < j {
			return i
		}
		return j
	}
	n, ans := min(len(word1), len(word2)), strings.Builder{}
	for i := 0; i < n; i++ {
		ans.WriteByte(word1[i])
		ans.WriteByte(word2[i])
	}
	if n != len(word1) {
		ans.Write([]byte(word1[n:]))
	}
	if n != len(word2) {
		ans.Write([]byte(word2[n:]))
	}
	return ans.String()
}
