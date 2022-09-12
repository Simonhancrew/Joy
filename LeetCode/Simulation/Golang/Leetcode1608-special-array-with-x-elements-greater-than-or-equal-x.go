package sbgo

import "sort"

func specialArray(nums []int) int {
	n := len(nums)
	sort.Slice(nums, func(i, j int) bool {
		return nums[i] > nums[j]
	})
	for i := 1; i <= n; i++ {
		if nums[i-1] >= i && (i == n || nums[i] < i) {
			return i
		}
	}
	return -1
}
