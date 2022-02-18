package sbgo

func findCenter(edges [][]int) int {
	n := len(edges) + 1
	st := make([]int, n+1)
	for i := 0; i < n-1; i++ {
		a, b := edges[i][0], edges[i][1]
		st[a]++
		st[b]++
	}
	for i := 1; i <= n; i++ {
		if st[i] == n-1 {
			return i
		}
	}
	return -1
}
