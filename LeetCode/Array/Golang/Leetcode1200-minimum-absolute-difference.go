package sbgo

import "sort"

func minimumAbsDifference(arr []int) [][]int {
	sort.Ints(arr)
	res, n, mini := [][]int{}, len(arr), 1<<31-1
	for i := 0; i < n-1; i++ {
		diff := arr[i+1] - arr[i]
		if diff == mini {
			res = append(res, []int{arr[i], arr[i+1]})
		} else if diff < mini {
			mini = diff
			res = [][]int{[]int{arr[i], arr[i+1]}}
		}
	}
	return res
}
