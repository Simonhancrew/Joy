package sbgo

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func min(x int, y int) int {
	if x < y {
		return x
	}
	return y
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
