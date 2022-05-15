package sbgo

import "math"

func largestTriangleArea(points [][]int) float64 {
	ans := -1.0
	for _, p := range points {
		for _, p1 := range points {
			for _, p2 := range points {
				x1, y1 := p[0], p[1]
				x2, y2, x3, y3 := p1[0]-x1, p1[1]-y1, p2[0]-x1, p2[1]-y1
				ans = max(ans, math.Abs(float64(x2*y3-x3*y2))/2.0)
			}
		}
	}
	return ans
}

func max(i, j float64) float64 {
	if i < j {
		return j
	}
	return i
}
