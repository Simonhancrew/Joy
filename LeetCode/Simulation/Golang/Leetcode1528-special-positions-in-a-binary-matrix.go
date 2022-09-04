package sbgo

func numSpecial(mat [][]int) int {
	n, m := len(mat), len(mat[0])
	c, r := make([]int, m), make([]int, n)
	ans := 0
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			r[i] += mat[i][j]
			c[j] += mat[i][j]
		}
	}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if mat[i][j] == 1 && c[j] == 1 && r[i] == 1 {
				ans++
			}
		}
	}
	return ans
}
