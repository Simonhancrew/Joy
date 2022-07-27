package sbgo

import "math/rand"

type Node struct {
	val  int
	next []*Node
}

type Skiplist struct {
	head *Node
}

func Constructor() Skiplist {
	return Skiplist{&Node{-1, make([]*Node, 8)}}
}

func (this *Skiplist) find(target int) []*Node {
	node := this.head
	pre := make([]*Node, 8)
	for i := 7; i >= 0; i-- {
		for node.next[i] != nil && node.next[i].val < target {
			node = node.next[i]
		}
		pre[i] = node
	}
	return pre
}

func (this *Skiplist) Search(target int) bool {
	pre := this.find(target)
	p := pre[0].next[0]
	return p != nil && p.val == target
}

func (this *Skiplist) Add(num int) {
	pre := this.find(num)
	p := &Node{num, make([]*Node, 8)}
	for i := 0; i < 8; i++ {
		p.next[i] = pre[i].next[i]
		pre[i].next[i] = p
		if rand.Int()%2 == 0 {
			break
		}
	}
}

func (this *Skiplist) Erase(num int) bool {
	pre := this.find(num)
	p := pre[0].next[0]
	if p == nil || p.val != num {
		return false
	}
	for i := 0; i < 8 && pre[i].next[i] == p; i++ {
		pre[i].next[i] = p.next[i]
	}
	return true
}
