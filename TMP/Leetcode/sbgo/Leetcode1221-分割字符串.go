package sbgo

func balancedStringSplit(s string) int {
	res, cnt := 0, 0
	for i := 0; i < len(s); i++ {
		if s[i] == 'R' {
			cnt++
		} else {
			cnt--
		}
		if cnt == 0 {
			res++
		}
	}
	return res
}
