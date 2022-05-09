package sbgo

func diStringMatch(s string) []int {
	n := len(s)
	l, r, ans := 0, n, make([]int, n+1)
	for i := 0; i < n; i++ {
		if s[i] == 'I' {
			ans[i] = l
			l++
		} else {
			ans[i] = r
			r--
		}
	}
	ans[n] = l
	return ans
}
