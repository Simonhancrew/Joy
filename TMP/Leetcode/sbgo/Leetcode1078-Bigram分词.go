package sbgo

import "strings"

func findOcurrences(text string, first string, second string) []string {
	rec := strings.Split(text, " ")
	n := len(rec)
	ans := []string{}
	for i := 0; i < n; i++ {
		if rec[i] == first && i+2 < n && rec[i+1] == second {
			ans = append(ans, rec[i+2])
		}
	}
	return ans
}
