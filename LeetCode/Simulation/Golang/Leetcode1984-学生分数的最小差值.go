package sbgo

import "sort"

func minimumDifference(nums []int, k int) int {
	ans, n := int(1e9), len(nums)
	sort.Ints(nums)
	for i := 0; i <= n-k; i++ {
		if nums[i+k-1]-nums[i] < ans {
			ans = nums[i+k-1] - nums[i]
		}
	}
	return ans
}
