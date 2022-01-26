package sbgo

func getMaximumGenerated(n int) (ans int) {
	if n == 0 {
		return 0
	}
	res := make([]int, n+1)
	res[1] = 1
	for i := 2; i <= n; i++ {
		res[i] = res[i>>1] + (i&1)*res[(i>>1)+1]
	}
	for _, val := range res {
		ans = max(ans, val)
	}
	return
}

func max(i, j int) int {
	if i < j {
		return j
	}
	return i
}
