package sbgo

type MyCircularDeque struct {
	buf    []int
	hh, tt int
}

func Constructor(k int) MyCircularDeque {
	hh, tt := 0, 0
	buf := make([]int, k+1)
	return MyCircularDeque{buf, hh, tt}
}

func (this *MyCircularDeque) get(x int) int {
	return (x + len(this.buf)) % len(this.buf)
}

func (this *MyCircularDeque) InsertFront(value int) bool {
	if this.IsFull() {
		return false
	}
	this.hh = this.get(this.hh - 1)
	this.buf[this.hh] = value
	return true
}

func (this *MyCircularDeque) InsertLast(value int) bool {
	if this.IsFull() {
		return false
	}
	this.buf[this.tt] = value
	this.tt = this.get(this.tt + 1)
	return true
}

func (this *MyCircularDeque) DeleteFront() bool {
	if this.IsEmpty() {
		return false
	}
	this.hh = this.get(this.hh + 1)
	return true
}

func (this *MyCircularDeque) DeleteLast() bool {
	if this.IsEmpty() {
		return false
	}
	this.tt = this.get(this.tt - 1)
	return true
}

func (this *MyCircularDeque) GetFront() int {
	if this.IsEmpty() {
		return -1
	}
	return this.buf[this.hh]
}

func (this *MyCircularDeque) GetRear() int {
	if this.IsEmpty() {
		return -1
	}
	return this.buf[this.get(this.tt-1)]
}

func (this *MyCircularDeque) IsEmpty() bool {
	return this.tt == this.hh
}

func (this *MyCircularDeque) IsFull() bool {
	return this.get(this.tt+1) == this.hh
}
