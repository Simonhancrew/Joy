package sbgo

import "strings"

func uncommonFromSentences(s1 string, s2 string) []string {
	st := map[string]int{}
	for _, word := range strings.Split(s1, " ") {
		st[word]++
	}
	for _, word := range strings.Split(s2, " ") {
		st[word]++
	}
	ans := []string{}
	for k, v := range st {
		if v == 1 {
			ans = append(ans, k)
		}
	}
	return ans
}
