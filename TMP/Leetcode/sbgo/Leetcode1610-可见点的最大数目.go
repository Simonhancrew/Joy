package sbgo

import (
	"math"
	"sort"
)

func visiblePoints(points [][]int, angle int, location []int) int {
	st, degree := 0, []float64{}
	for _, point := range points {
		if point[0] == location[0] && point[1] == location[1] {
			st++
			continue
		}
		dx, dy := float64(point[0]-location[0]), float64(point[1]-location[1])
		dg := math.Atan2(dy, dx)
		degree = append(degree, dg)
	}
	sort.Float64s(degree)
	n := len(degree)
	for i := 0; i < n; i++ {
		degree = append(degree, degree[i]+math.Pi*2)
	}
	cnt := 0
	angled := float64(angle) * math.Pi / 180
	for i, j := 0, 0; i < n; i++ {
		for j < len(degree) && degree[j]-degree[i] <= angled {
			j++
		}
		if cnt < j-i {
			cnt = j - i
		}
	}
	return cnt + st
}
