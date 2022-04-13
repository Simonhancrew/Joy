package sbgo

import "math/rand"

type RandomizedSet struct {
	nums []int
	mp   map[int]int
}

func Constructor() RandomizedSet {
	nums := []int{}
	mp := map[int]int{}
	return RandomizedSet{nums, mp}
}

func (this *RandomizedSet) Insert(val int) bool {
	if _, ok := this.mp[val]; ok {
		return false
	}
	this.nums = append(this.nums, val)
	this.mp[val] = len(this.nums) - 1
	return true
}

func (this *RandomizedSet) Remove(val int) bool {
	if _, ok := this.mp[val]; !ok {
		return false
	}
	tar := this.nums[len(this.nums)-1]
	px, py := this.mp[val], this.mp[tar]
	this.nums[px], this.nums[py] = this.nums[py], this.nums[px]
	this.nums = this.nums[:len(this.nums)-1]
	this.mp[tar] = this.mp[val]
	delete(this.mp, val)
	return true
}

func (this *RandomizedSet) GetRandom() int {
	r := int64(len(this.nums))
	idx := int(rand.Int63n(r))
	return this.nums[idx]
}
