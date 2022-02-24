package sbgo

func findBall(grid [][]int) []int {
	n, m, ans := len(grid), len(grid[0]), []int{}
	for i := 0; i < m; i++ {
		x, y, z := 0, i, 0
		for x < n {
			if z == 0 {
				if grid[x][y] == 1 {
					if y+1 >= m || grid[x][y+1] == -1 {
						y = -1
					} else {
						y, z = y+1, 1
					}
				} else {
					if y-1 < 0 || grid[x][y-1] == 1 {
						y = -1
					} else {
						y, z = y-1, 1
					}
				}
			} else {
				x, z = x+1, 0
			}
			if y == -1 {
				break
			}
		}
		ans = append(ans, y)
	}
	return ans
}
