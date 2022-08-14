package sbgo

func maxScore(s string) int {
	lhs, rhs := 0, 0
	for _, ch := range s {
		if ch == '1' {
			rhs++
		}
	}
	res, n := 0, len(s)
	for i := 0; i < n-1; i++ {
		if s[i] == '1' {
			rhs--
		} else {
			lhs++
		}
		if res < lhs+rhs {
			res = lhs + rhs
		}
	}
	return res
}
