package sbgo

type MovingAverage struct {
	sum, size int
	arr       []int
}

/** Initialize your data structure here. */
func Constructor(size int) MovingAverage {
	sum, arr, size := 0, []int{}, size
	return MovingAverage{sum, size, arr}
}

func (this *MovingAverage) Next(val int) float64 {
	this.arr = append(this.arr, val)
	this.sum += val
	if len(this.arr) > this.size {
		this.sum -= this.arr[0]
		this.arr = this.arr[1:]
	}
	return float64(this.sum) / float64(len(this.arr))
}
