package sbgo

import "sort"

func makesquare(arr []int) bool {
	sum := 0
	for _, val := range arr {
		sum += val
	}
	if sum%4 != 0 {
		return false
	}
	sort.Slice(arr, func(i, j int) bool {
		return arr[i] > arr[j]
	})
	edge := make([]int, 4)
	var dfs func(u int) bool
	dfs = func(u int) bool {
		if u == len(arr) {
			return true
		}
		for i := 0; i < 4; i++ {
			edge[i] += arr[u]
			if edge[i] <= sum/4 && dfs(u+1) {
				return true
			}
			edge[i] -= arr[u]
		}
		return false
	}
	return dfs(0)
}
