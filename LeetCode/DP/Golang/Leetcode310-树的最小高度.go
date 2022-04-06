package sbgo

import "fmt"

func findMinHeightTrees(n int, edges [][]int) []int {
	g := make([][]int, n)
	d1, d2, up, p1 := make([]int, n), make([]int, n), make([]int, n), make([]int, n)

	for _, ed := range edges {
		a, b := ed[0], ed[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	var dfs1 func(u, fa int)
	var dfs2 func(u, fa int)

	dfs1 = func(u, fa int) {
		for _, x := range g[u] {
			if x == fa {
				continue
			}
			dfs1(x, u)
			d := d1[x] + 1
			if d >= d1[u] {
				d2[u], d1[u] = d1[u], d
				p1[u] = x
			} else if d > d2[u] {
				d2[u] = d
			}

		}
	}

	dfs2 = func(u, fa int) {
		for _, x := range g[u] {
			if x == fa {
				continue
			}
			if p1[u] == x {
				up[x] = max(up[u], d2[u]) + 1
			} else {
				up[x] = max(up[u], d1[u]) + 1
			}
			dfs2(x, u)
		}
	}

	dfs1(0, -1)
	dfs2(0, -1)

	mind, res := n+1, []int{}
	for i := 0; i < n; i++ {
		mind = min(mind, max(up[i], d1[i]))
	}

	fmt.Println(mind)

	for i := 0; i < n; i++ {
		if mind == max(up[i], d1[i]) {
			res = append(res, i)
		}
	}

	return res
}
