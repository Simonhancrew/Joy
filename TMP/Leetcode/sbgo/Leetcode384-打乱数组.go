package sbgo

import (
	"math/rand"
	"time"
)

type Solution struct {
	memo []int
}

func Constructor(nums []int) Solution {
	memo := nums
	rand.Seed(time.Now().Unix())
	return Solution{memo}
}

func (this *Solution) Reset() []int {
	return this.memo
}

func (this *Solution) Shuffle() []int {
	cp := make([]int, len(this.memo))
	copy(cp, this.memo[:])
	rand.Shuffle(len(cp), func(i, j int) {
		cp[i], cp[j] = cp[j], cp[i]
	})
	return cp
}
