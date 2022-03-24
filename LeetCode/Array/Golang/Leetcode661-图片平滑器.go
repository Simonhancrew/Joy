package sbgo

func imageSmoother(img [][]int) [][]int {
	n, m := len(img), len(img[0])
	res := make([][]int, n)
	for i := 0; i < n; i++ {
		res[i] = make([]int, m)
	}
	get := func(x, y int) int {
		acc, div := 0, 0
		for i := -1; i <= 1; i++ {
			for j := -1; j <= 1; j++ {
				nx, ny := x+i, y+j
				if nx < 0 || nx >= n || ny < 0 || ny >= m {
					continue
				}
				acc, div = acc+img[nx][ny], div+1
			}
		}
		return acc / div
	}

	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			res[i][j] = get(i, j)
		}
	}
	return res
}
