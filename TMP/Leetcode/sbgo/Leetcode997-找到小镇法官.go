package sbgo

func findJudge(n int, trust [][]int) int {
	din, dout := make([]int, n+1), make([]int, n+1)
	res := -1
	for _, p := range trust {
		a, b := p[0], p[1]
		din[b]++
		dout[a]++
	}
	for i := 1; i <= n; i++ {
		if dout[i] == 0 && din[i] == n-1 {
			if res != -1 {
				return -1
			}
			res = i
		}
	}
	return res
}
