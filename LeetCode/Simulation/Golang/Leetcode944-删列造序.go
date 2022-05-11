package sbgo

func minDeletionSize(s []string) int {
	res, n, m := 0, len(s), len(s[0])
	for j := 0; j < m; j++ {
		for i := 1; i < n; i++ {
			if s[i-1][j] > s[i][j] {
				res++
				break
			}
		}
	}
	return res
}
