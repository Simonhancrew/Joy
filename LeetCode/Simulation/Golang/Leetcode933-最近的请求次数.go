package sbgo

type RecentCounter struct {
	q []int
}

func Constructor() RecentCounter {
	q := []int{}
	return RecentCounter{q}
}

func (this *RecentCounter) Ping(t int) int {
	this.q = append(this.q, t)
	for t-this.q[0] > 3000 {
		this.q = this.q[1:]
	}
	return len(this.q)
}
