package sbgo

func minAddToMakeValid(s string) int {
	l, r := 0, 0
	for _, c := range s {
		if c == '(' {
			l++
		} else if c == ')' {
			if l == 0 {
				r++
			} else {
				l--
			}
		}
	}
	return l + r
}
