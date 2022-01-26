package sbgo

type TopVotedCandidate struct {
	t, win []int
}

func Constructor(persons []int, times []int) TopVotedCandidate {
	n := len(times)
	sum := make([]int, n)
	maxc, maxp := 0, -1
	win := make([]int, n)
	for i := 0; i < n; i++ {
		p := persons[i]
		sum[p]++
		if sum[p] >= maxc {
			maxc = sum[p]
			maxp = p
		}
		win[i] = maxp
	}
	return TopVotedCandidate{times, win}
}

func (this *TopVotedCandidate) Q(t int) int {
	l, r := 0, len(this.t)-1
	for l < r {
		mid := (l + r + 1) >> 1
		if this.t[mid] <= t {
			l = mid
		} else {
			r = mid - 1
		}
	}
	return this.win[l]
}
