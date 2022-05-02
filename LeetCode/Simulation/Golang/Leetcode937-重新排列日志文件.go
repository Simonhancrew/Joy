package sbgo

import (
	"sort"
	"strings"
	"unicode"
)

func reorderLogFiles(logs []string) []string {
	sort.SliceStable(logs, func(i, j int) bool {
		s, t := logs[i], logs[j]
		s1 := strings.SplitN(s, " ", 2)[1]
		s2 := strings.SplitN(t, " ", 2)[1]
		isd1 := unicode.IsDigit(rune(s1[0]))
		isd2 := unicode.IsDigit(rune(s2[0]))
		if isd1 && isd2 {
			return false
		}
		if !isd2 && !isd1 {
			return s1 < s2 || s1 == s2 && s < t
		}
		return !isd1
	})
	return logs
}
