package sbgo

import "math/rand"

type Solution struct {
	nums []int
}

func Constructor(nums []int) Solution {
	return Solution{nums}
}

func (this *Solution) Pick(target int) int {
	n, res, cnt := len(this.nums), 0, 0
	for i := 0; i < n; i++ {
		if this.nums[i] == target {
			cnt++
			if rand.Intn(cnt) == 0 {
				res = i
			}
		}
	}
	return res
}
