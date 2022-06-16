package sbgio

import "sort"

func findPairs(nums []int, k int) int {
	n, ans := len(nums), 0
	sort.Ints(nums)
	for i, j := 0, 0; i < n; i++ {
		for i < n-1 && nums[i+1] == nums[i] {
			i++
		}
		for j < i && nums[i]-nums[j] > k {
			j++
		}
		if j < i && nums[i]-nums[j] == k {
			ans++
		}
	}
	return ans
}
