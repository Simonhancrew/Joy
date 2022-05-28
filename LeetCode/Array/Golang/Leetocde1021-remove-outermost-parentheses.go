package sbgo

import "strings"

func removeOuterParentheses(s string) string {
	sb, n := strings.Builder{}, len(s)
	for i := 0; i < n; i++ {
		j, cnt := i+1, 1
		for j < n && cnt != 0 {
			if s[j] == '(' {
				cnt++
			} else {
				cnt--
			}
			j++
		}
		sb.WriteString(s[i+1 : j-1])
		i = j - 1
	}
	return sb.String()
}
