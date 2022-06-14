package sbgo

func findDiagonalOrder(mat [][]int) []int {
	n, m, ans := len(mat), len(mat[0]), []int{}
	for i := 0; i < n+m-1; i++ {
		if i%2 == 1 {
			x, y := 0, i
			if i >= m {
				x, y = i-m+1, m-1
			}
			for x < n && y >= 0 {
				// fmt.Println(x,y)
				ans = append(ans, mat[x][y])
				x++
				y--
			}
		} else {
			x, y := i, 0
			if i >= n {
				x, y = n-1, i-n+1
			}
			for x >= 0 && y < m {
				ans = append(ans, mat[x][y])
				x--
				y++
			}
		}
	}
	return ans
}
