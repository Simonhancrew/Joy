package sbgo

import "strings"

func greatestLetter(s string) string {
	n := len(s)
	ans := ""
	lo, up := make([]int, 26), make([]int, 26)
	for i := 0; i < n; i++ {
		if s[i] >= 'a' && s[i] <= 'z' {
			lo[s[i]-'a']++
			if up[s[i]-'a'] > 0 && (len(ans) == 0 || ans[0]-'A' < s[i]-'a') {
				ans = strings.ToUpper(string(s[i]))
			}
		} else {
			up[s[i]-'A']++
			if lo[s[i]-'A'] > 0 && (len(ans) == 0 || ans[0] < s[i]) {
				ans = string(s[i])
			}
		}
	}
	return ans
}
