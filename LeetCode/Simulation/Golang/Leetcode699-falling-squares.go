package sbgo

func fallingSquares(positions [][]int) []int {
	n := len(positions)
	ans := make([]int, n)
	for i := 0; i < n; i++ {
		l1, r1 := positions[i][0], positions[i][1]+positions[i][0]-1
		ans[i] = positions[i][1]
		for j := 0; j < i; j++ {
			l2, r2 := positions[j][0], positions[j][1]+positions[j][0]-1
			if r1 >= l2 && r2 >= l1 {
				ans[i] = max(ans[i], ans[j]+positions[i][1])
			}
		}
	}
	for i := 1; i < n; i++ {
		ans[i] = max(ans[i], ans[i-1])
	}
	return ans
}

func max(i, j int) int {
	if i < j {
		return j
	}
	return i
}
