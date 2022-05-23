package sbgo

import "sort"

func cutOffTree(forest [][]int) int {
	n, m := len(forest), len(forest[0])
	trees := [][]int{}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if forest[i][j] > 1 {
				trees = append(trees, []int{i, j, forest[i][j]})
			}
		}
	}
	sort.Slice(trees, func(i, j int) bool {
		return trees[i][2] < trees[j][2]
	})

	var bfs func(i, j []int) int
	bfs = func(st, to []int) int {
		if st[0] == to[0] && st[1] == to[1] {
			return 0
		}
		dx, dy := [4]int{0, 1, 0, -1}, [4]int{1, 0, -1, 0}
		dist, q := make([][]int, n), [][]int{}

		for i := 0; i < n; i++ {
			dist[i] = make([]int, m)
			for j := 0; j < m; j++ {
				dist[i][j] = 1000000
			}
		}
		dist[st[0]][st[1]] = 0
		q = append(q, []int{st[0], st[1]})

		for len(q) != 0 {
			t := q[0]
			q = q[1:]
			for i := 0; i < 4; i++ {
				nx, ny := t[0]+dx[i], t[1]+dy[i]
				if nx >= 0 && nx < n && ny >= 0 && ny < m && forest[nx][ny] != 0 {
					if dist[nx][ny] > dist[t[0]][t[1]]+1 {
						dist[nx][ny] = dist[t[0]][t[1]] + 1
						if nx == to[0] && ny == to[1] {
							return dist[nx][ny]
						}
						q = append(q, []int{nx, ny})
					}
				}
			}
		}
		return -1
	}

	res, st := 0, []int{0, 0}
	for _, to := range trees {
		t := bfs(st, to)
		// fmt.Println(t)
		if t == -1 {
			return -1
		}
		res += t
		st = to
	}
	return res
}
