package sbgo

import "sort"

func heightChecker(heights []int) (ans int) {
	n := len(heights)
	rec := make([]int, n)
	for i := range heights {
		rec[i] = heights[i]
	}
	sort.Ints(rec)
	for i := 0; i < n; i++ {
		if rec[i] != heights[i] {
			ans++
		}
	}
	return
}
