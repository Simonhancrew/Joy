package sbgo

import "math/rand"

type Solution struct {
	rec [][]int
	s   []int
}

func Constructor(rects [][]int) Solution {
	s := []int{0}
	for _, x := range rects {
		dx, dy := x[2]-x[0]+1, x[3]-x[1]+1
		s = append(s, dx*dy+s[len(s)-1])
	}
	return Solution{
		rects,
		s,
	}
}

func (this *Solution) Pick() []int {
	tar := rand.Intn(this.s[len(this.s)-1]) + 1
	l, r := 1, len(this.rec)
	for l < r {
		mid := (l + r) >> 1
		if this.s[mid] >= tar {
			r = mid
		} else {
			l = mid + 1
		}
	}
	t := this.rec[r-1]
	dx, dy := t[2]-t[0]+1, t[3]-t[1]+1
	return []int{rand.Intn(dx) + t[0], rand.Intn(dy) + t[1]}
}
