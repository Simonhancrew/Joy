package sbgo

func loudAndRich(richer [][]int, quiet []int) []int {
	n := len(quiet)
	g := make([][]int, n)
	for i := range g {
		g[i] = []int{}
	}
	for _, rich := range richer {
		a, b := rich[0], rich[1]
		g[b] = append(g[b], a)
	}
	ans := make([]int, n)
	for i := range ans {
		ans[i] = -1
	}
	var dfs func(int)
	dfs = func(u int) {
		if ans[u] != -1 {
			return
		}
		ans[u] = u
		for _, v := range g[u] {
			dfs(v)
			if quiet[ans[v]] < quiet[ans[u]] {
				ans[u] = ans[v]
			}
		}
	}
	for i := 0; i < n; i++ {
		dfs(i)
	}
	return ans
}
