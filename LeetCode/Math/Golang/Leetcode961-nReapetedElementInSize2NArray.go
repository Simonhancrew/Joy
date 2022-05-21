package sbgo

import "math/rand"

func repeatedNTimes(nums []int) int {
	n := len(nums)
	for true {
		x, y := rand.Intn(n), rand.Intn(n)
		if x != y && nums[x] == nums[y] {
			return nums[x]
		}
	}
	return -1
}
