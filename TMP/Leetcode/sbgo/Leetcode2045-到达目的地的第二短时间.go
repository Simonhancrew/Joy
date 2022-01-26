package sbgo

import "math"

func secondMinimum(n int, edges [][]int, time int, change int) int {
	graph := make([][]int, n+1)
	for _, edge := range edges {
		graph[edge[0]] = append(graph[edge[0]], edge[1])
		graph[edge[1]] = append(graph[edge[1]], edge[0])
	}
	d1, d2 := make([]int, n+1), make([]int, n+1)
	for i := 1; i <= n; i++ {
		d1[i] = math.MaxInt32
		d2[i] = math.MaxInt32
	}
	type pair struct{ d, node int }
	q := []pair{}
	q = append(q, pair{0, 1})
	for len(q) != 0 {
		t := q[0]
		q = q[1:]
		d, node := t.d, t.node
		for _, ne := range graph[node] {
			if d1[ne] > d+1 {
				d2[ne] = d1[ne]
				d1[ne] = d + 1
				q = append(q, pair{d + 1, ne})
			} else if d1[ne] < d+1 && d2[ne] > d+1 {
				d2[ne] = d + 1
				q = append(q, pair{d + 1, ne})
			}
		}
	}
	ans := 0
	for i := 0; i < d2[n]; i++ {
		a, b := ans/change, ans%change
		wait := 0
		if a%2 != 0 {
			wait = change - b
		}
		ans += wait + time
	}
	return ans
}
