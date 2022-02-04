package sbgo

func countGoodRectangles(rectangles [][]int) int {
	mx, cnt := -1, 0
	for _, edge := range rectangles {
		key := min(edge[0], edge[1])
		if mx == key {
			cnt++
		} else if mx < key {
			cnt = 1
			mx = key
		}
	}
	return cnt
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}
