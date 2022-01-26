package sbgo

func countSegments(s string) int {
	cnt, n := 0, len(s)
	for i := 0; i < n; i++ {
		for i < n && s[i] == ' ' {
			i++
		}
		if i == n {
			break
		}
		for i < n && s[i] != ' ' {
			i++
		}
		cnt++
	}
	return cnt
}
