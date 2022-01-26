package sbgo

import "math/rand"

type Solution struct {
	m, n, k int
	mp      map[int]int
}

func Constructor(m int, n int) Solution {
	return Solution{m: m, n: n, k: m * n, mp: map[int]int{}}
}

func (this *Solution) Flip() []int {
	idx := rand.Intn(this.k)
	real := idx
	if _, ok := this.mp[idx]; ok {
		real = this.mp[idx]
	}
	// fmt.Println(real)
	if _, ok := this.mp[this.k-1]; ok {
		this.mp[idx] = this.mp[this.k-1]
		delete(this.mp, this.k-1)
	} else {
		this.mp[idx] = this.k - 1
	}
	this.k--
	return []int{real / this.n, real % this.n}
}

func (this *Solution) Reset() {
	this.k = this.m * this.n
	this.mp = map[int]int{}
}
