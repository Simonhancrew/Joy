package sbgo

import "github.com/emirpasic/gods/trees/redblacktree"

type MyCalendarThree struct {
	*redblacktree.Tree
}

func Constructor() MyCalendarThree {
	return MyCalendarThree{redblacktree.NewWithIntComparator()}
}

func (t MyCalendarThree) add(idx, val int) {
	if num, ok := t.Get(idx); ok {
		val += num.(int)
	}
	t.Put(idx, val)
}

func (this *MyCalendarThree) Book(start int, end int) int {
	this.add(start, 1)
	this.add(end, -1)
	sum, res := 0, 0
	for it := this.Iterator(); it.Next(); {
		sum += it.Value().(int)
		if sum > res {
			res = sum
		}
	}
	return res
}
