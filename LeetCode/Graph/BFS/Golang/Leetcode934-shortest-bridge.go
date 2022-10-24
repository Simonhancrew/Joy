package sbgo

func shortestBridge(grid [][]int) int {
	n, m := len(grid), len(grid[0])
	dis := make([][]int, n)
	for i := 0; i < n; i++ {
		dis[i] = make([]int, m)
		for j := 0; j < m; j++ {
			dis[i][j] = 100000
		}
	}
	q := [][]int{}
	var dfs func(x, y int)
	dx, dy := []int{0, -1, 0, 1}, []int{-1, 0, 1, 0}
	dfs = func(x, y int) {
		dis[x][y] = 0
		grid[x][y] = 0
		q = append(q, []int{x, y})
		for i := 0; i < 4; i++ {
			nx, ny := x+dx[i], y+dy[i]
			if nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1 {
				dfs(nx, ny)
			}
		}
	}

	bfs := func() int {
		for len(q) != 0 {
			t := q[0]
			q = q[1:]
			for i := 0; i < 4; i++ {
				nx, ny := t[0]+dx[i], t[1]+dy[i]
				if nx >= n || ny >= m || nx < 0 || ny < 0 {
					continue
				}
				if grid[nx][ny] == 1 {
					return dis[t[0]][t[1]]
				}
				if dis[nx][ny] > dis[t[0]][t[1]]+1 {
					dis[nx][ny] = dis[t[0]][t[1]] + 1
					q = append(q, []int{nx, ny})
				}
			}
		}
		return -1
	}

	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if grid[i][j] == 1 {
				dfs(i, j)
				return bfs()
			}
		}
	}
	return -1
}
