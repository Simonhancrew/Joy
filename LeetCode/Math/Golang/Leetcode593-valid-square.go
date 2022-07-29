package sbgo

import "sort"

func validSquare(p1 []int, p2 []int, p3 []int, p4 []int) bool {
	p := [][]int{p1, p2, p3, p4}
	d := []int{}
	calcu := func(a, b []int) int {
		dx, dy := a[0]-b[0], a[1]-b[1]
		return dx*dx + dy*dy
	}
	for i := 0; i < 4; i++ {
		for j := i + 1; j < 4; j++ {
			d = append(d, calcu(p[i], p[j]))
		}
	}
	sort.Ints(d)
	if d[0] == 0 {
		return false
	}
	return d[0] == d[1] && d[1] == d[2] && d[2] == d[3] && d[4] == d[5]
}
