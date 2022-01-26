package sbgo

import "math/rand"

type Solution struct {
	node []int
}

func Constructor(head *ListNode) Solution {
	t := []int{}
	for head != nil {
		t = append(t, head.Val)
		head = head.Next
	}
	return Solution{t}
}

func (this *Solution) GetRandom() int {
	return this.node[rand.Intn(len(this.node))]
}
