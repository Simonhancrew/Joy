package sbgo

import "strings"

func defangIPaddr(address string) string {
	sb := strings.Builder{}
	for _, ch := range address {
		if ch == '.' {
			sb.WriteString("[.]")
		} else {
			sb.WriteRune(ch)
		}
	}
	return sb.String()
}
