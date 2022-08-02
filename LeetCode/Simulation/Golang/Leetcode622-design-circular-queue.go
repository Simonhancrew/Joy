package sbgo

type MyCircularQueue struct {
    hh, tt int
    q []int
}


func Constructor(k int) MyCircularQueue {
    q := make([]int,k + 1)
    hh,tt := 0,0
    return MyCircularQueue{hh,tt,q}
}


func (this *MyCircularQueue) EnQueue(value int) bool {
    if this.IsFull() {
        return false
    }
    this.q[this.tt] = value
    this.tt += 1
    if this.tt == len(this.q) {
        this.tt = 0
    }
    return true
}


func (this *MyCircularQueue) DeQueue() bool {
    if this.IsEmpty() {
        return false
    }
    this.hh++
    if this.hh == len(this.q) {
        this.hh = 0
    }
    return true
}


func (this *MyCircularQueue) Front() int {
    if this.IsEmpty() {
        return -1
    }
    return this.q[this.hh]
}


func (this *MyCircularQueue) Rear() int {
    if this.IsEmpty() {
        return -1
    }
    t := this.tt - 1
    if t < 0 {
        t += len(this.q)
    }
    return this.q[t]
}


func (this *MyCircularQueue) IsEmpty() bool {
    return this.hh == this.tt 
}


func (this *MyCircularQueue) IsFull() bool {
    return (this.tt + 1) % len(this.q) == this.hh
}

