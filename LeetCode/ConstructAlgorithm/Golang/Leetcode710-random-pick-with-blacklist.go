package sbgo

import "math/rand"

type Solution struct {
	mp map[int]int
	bd int
}

func Constructor(n int, blacklist []int) Solution {
	mp := make(map[int]int)
	st, m := map[int]bool{}, len(blacklist)
	bd := n - m
	for _, x := range blacklist {
		if x >= bd {
			st[x] = true
		}
	}
	it := bd
	for _, x := range blacklist {
		if x < bd {
			for st[it] {
				it++
			}
			mp[x] = it
			it++
		}
	}
	return Solution{mp, bd}
}

func (this *Solution) Pick() int {
	k := rand.Intn(this.bd)
	if this.mp[k] > 0 {
		return this.mp[k]
	}
	return k
}
