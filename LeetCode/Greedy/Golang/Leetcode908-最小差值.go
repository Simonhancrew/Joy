package sbgo

func smallestRangeI(nums []int, k int) int {
	x, y := 100000, -1
	for _, e := range nums {
		x = min(x, e)
		y = max(y, e)
	}
	return max(0, y-x-2*k)
}

func max(i, j int) int {
	if i < j {
		return j
	}
	return i
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}
