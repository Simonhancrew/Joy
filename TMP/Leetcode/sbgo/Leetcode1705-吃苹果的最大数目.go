package sbgo

import "container/heap"

type pair struct {
	a, t int
}
type hp []pair

func (h hp) Len() int            { return len(h) }
func (h hp) Swap(i, j int)       { h[i], h[j] = h[j], h[i] }
func (h hp) Less(i, j int) bool  { return h[i].t < h[j].t }
func (h *hp) Push(v interface{}) { *h = append(*h, v.(pair)) }
func (h *hp) Pop() interface{}   { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }

func eatenApples(apples []int, days []int) int {
	h := hp{}
	ans, time, n := 0, 0, len(apples)
	for len(h) != 0 || time < n {
		if time < n && apples[time] > 0 {
			heap.Push(&h, pair{apples[time], time + days[time] - 1})
		}
		for len(h) > 0 && h[len(h)-1].t < time {
			heap.Pop(&h)
		}
		if len(h) > 0 {
			t := heap.Pop(&h).(pair)
			if t.a-1 > 0 && t.t > time {
				heap.Push(&h, pair{t.a - 1, t.t})
			}
			ans++
		}
		time++
	}
	return ans
}
