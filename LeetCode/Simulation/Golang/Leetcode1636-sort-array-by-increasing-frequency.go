package sbgo

import "sort"

func frequencySort(nums []int) []int {
	mp := map[int]int{}
	for _, x := range nums {
		mp[x]++
	}
	sort.Slice(nums, func(i, j int) bool {
		a, b := nums[i], nums[j]
		return mp[a] < mp[b] || mp[a] == mp[b] && a > b
	})
	return nums
}
