package sbgo

import "strings"

func checkRecord(s string) bool {
	if strings.Contains(s, "LLL") {
		return false
	}
	cnt := 0
	for _, ch := range s {
		if ch == 'A' {
			cnt++
		}
	}
	if cnt >= 2 {
		return false
	}
	return true
}
