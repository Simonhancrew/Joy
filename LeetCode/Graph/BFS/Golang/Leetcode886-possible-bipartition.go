package sbgo

func possibleBipartition(n int, dislikes [][]int) bool {
	g := make([][]int, n+1)
	for _, d := range dislikes {
		g[d[0]] = append(g[d[0]], d[1])
		g[d[1]] = append(g[d[1]], d[0])
	}
	color := make([]int, n+1)
	var dfs func(i, j int) bool
	dfs = func(u, c int) bool {
		color[u] = c
		for _, v := range g[u] {
			if color[v] != 0 {
				if color[v] == color[u] {
					return false
				}
			} else if !dfs(v, 3-c) {
				return false
			}
		}
		return true
	}
	for i := 1; i <= n; i++ {
		if color[i] == 0 && !dfs(i, 1) {
			return false
		}
	}
	return true
}
