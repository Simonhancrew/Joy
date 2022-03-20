package sbgo

func networkBecomesIdle(edges [][]int, patience []int) int {
	n := len(patience)
	g := make([][]int, n)
	for i := 0; i < len(edges); i++ {
		g[edges[i][0]] = append(g[edges[i][0]], edges[i][1])
		g[edges[i][1]] = append(g[edges[i][1]], edges[i][0])
	}
	d := make([]int, n)
	st := make([]int, n)
	st[0] = 1
	q := []int{0}
	for len(q) != 0 {
		t := q[0]
		q = q[1:]
		for _, v := range g[t] {
			if st[v] == 1 {
				continue
			}
			d[v] = d[t] + 1
			st[v] = 1
			q = append(q, v)
		}
	}
	// fmt.Println(d)
	ans := 0
	for i := 1; i < n; i++ {
		di, t := 2*d[i], patience[i]
		cur := 0
		if di <= t {
			cur = di
		} else {
			cur = (di-1)/t*t + di
		}
		if cur > ans {
			ans = cur
		}
	}
	return ans + 1
}
