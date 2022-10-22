package sbgo

import "sort"

func jobScheduling(startTime []int, endTime []int, profit []int) int {
	n, arr := len(startTime), [][]int{}
	for i := 0; i < n; i++ {
		arr = append(arr, []int{startTime[i], endTime[i], profit[i]})
	}
	sort.Slice(arr, func(i, j int) bool {
		return arr[i][1] < arr[j][1]
	})
	max := func(i, j int) int {
		if i < j {
			return j
		}
		return i
	}
	f := make([]int, n)
	f[0] = arr[0][2]
	for i := 1; i < n; i++ {
		f[i] = max(f[i-1], arr[i][2])
		if arr[i][0] >= arr[0][1] {
			l, r := 0, i-1
			for l < r {
				mid := (l + r + 1) >> 1
				if arr[mid][1] <= arr[i][0] {
					l = mid
				} else {
					r = mid - 1
				}
			}
			f[i] = max(f[i], f[r]+arr[i][2])
		}
	}
	return f[n-1]
}
