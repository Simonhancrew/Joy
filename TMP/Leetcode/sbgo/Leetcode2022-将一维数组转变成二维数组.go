package sbgo

func construct2DArray(original []int, m int, n int) [][]int {
	if m*n != len(original) {
		return [][]int{}
	}
	ans := [][]int{}
	for i := 0; i < m; i++ {
		t := []int{}
		for j := 0; j < n; j++ {
			t = append(t, original[i*n+j])
		}
		ans = append(ans, t)
	}
	return ans
}
