package sbgo

import "sort"

func minMoves2(nums []int) int {
	sort.Ints(nums)
	n, res := len(nums), 0
	var tar = nums[n/2]
	for _, x := range nums {
		if tar > x {
			res += tar - x
		} else {
			res += x - tar
		}
	}
	return res
}
