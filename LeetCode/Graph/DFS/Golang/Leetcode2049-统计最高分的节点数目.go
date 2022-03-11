package sbgo

func countHighestScoreNodes(parents []int) int {
	n, cnt, mx := len(parents), 0, -1
	sz, g := make([]int, n), make([][]int, n)
	for i := 1; i < n; i++ {
		g[parents[i]] = append(g[parents[i]], i)
	}
	var dfs func(int)
	dfs = func(u int) {
		sz[u] = 1
		tmp := 1
		for _, s := range g[u] {
			dfs(s)
			sz[u] += sz[s]
			tmp *= sz[s]
		}
		if n-sz[u] > 0 {
			tmp *= n - sz[u]
		}
		if tmp > mx {
			mx = tmp
			cnt = 1
		} else if tmp == mx {
			cnt++
		}
	}
	dfs(0)
	return cnt
}
