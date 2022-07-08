package sbgo

func minCostToMoveChips(position []int) int {
	o, e := 0, 0
	for _, p := range position {
		if p%2 == 0 {
			o++
		} else {
			e++
		}
	}
	if o == 0 || e == 0 {
		return 0
	}
	return min(o, e)
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}
