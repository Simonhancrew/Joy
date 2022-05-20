package sbgo

import "sort"

func findRightInterval(intervals [][]int) []int {
	n := len(intervals)
	res := make([]int, n)
	for i := 0; i < n; i++ {
		res[i] = -1
		intervals[i] = append(intervals[i], i)
	}
	sort.Slice(intervals, func(a, b int) bool {
		return intervals[a][0] < intervals[b][0]
	})
	for i, x := range intervals {
		l, r := i, n-1
		for l < r {
			mid := (l + r) >> 1
			if intervals[mid][0] >= x[1] {
				r = mid
			} else {
				l = mid + 1
			}
		}
		if intervals[l][0] >= x[1] {
			res[x[2]] = intervals[l][2]
		}
	}
	return res
}
