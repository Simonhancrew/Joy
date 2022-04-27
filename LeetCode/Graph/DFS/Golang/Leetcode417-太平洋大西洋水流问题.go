package sbgo

func pacificAtlantic(heights [][]int) [][]int {
	n, m, res := len(heights), len(heights[0]), [][]int{}
	st := make([][]int, n)
	dx, dy := []int{0, 1, 0, -1}, []int{1, 0, -1, 0}
	for i := 0; i < n; i++ {
		st[i] = make([]int, m)
	}
	var dfs func(x, y, t int)
	dfs = func(x, y, t int) {
		if st[x][y]&t != 0 {
			return
		}
		st[x][y] |= t
		for i := 0; i < 4; i++ {
			nx, ny := x+dx[i], y+dy[i]
			if nx < 0 || nx >= n || ny < 0 || ny >= m {
				continue
			}
			if heights[nx][ny] < heights[x][y] {
				continue
			}
			dfs(nx, ny, t)
		}
	}

	for i := 0; i < n; i++ {
		dfs(i, 0, 1)
		dfs(i, m-1, 2)
	}
	for i := 0; i < m; i++ {
		dfs(0, i, 1)
		dfs(n-1, i, 2)
	}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if st[i][j] == 3 {
				res = append(res, []int{i, j})
			}
		}
	}
	return res
}
