package sbgo

import "sort"

func smallestDistancePair(nums []int, k int) int {
	sort.Ints(nums)
	l, r := 0, int(1e6)
	get := func(mid int) int {
		res := 0
		for i, j := 0, 0; i < len(nums); i++ {
			for nums[i]-nums[j] > mid {
				j++
			}
			res += i - j
		}
		return res
	}
	for l < r {
		mid := (l + r) >> 1
		if get(mid) >= k {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return r
}
