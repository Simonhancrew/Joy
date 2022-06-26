package sbgo

func isBoomerang(points [][]int) bool {
	k1 := (points[1][1] - points[0][1]) * (points[2][0] - points[1][0])
	k2 := (points[2][1] - points[1][1]) * (points[1][0] - points[0][0])
	return k1 != k2
}