package sbgo

func findMinMoves(machines []int) int {
	tot, n := 0, len(machines)
	for _, val := range machines {
		tot += val
	}
	if tot%n != 0 {
		return -1
	}
	avg, l, r, ans := tot/n, 0, tot, 0
	for i := 0; i < n; i++ {
		r -= machines[i]
		r2l := max(i*avg-l, 0)
		l2r := max((n-i-1)*avg-r, 0)
		ans = max(ans, l2r+r2l)
		l += machines[i]
	}
	return ans
}

func max(i, j int) int {
	if i < j {
		return j
	}
	return i
}
