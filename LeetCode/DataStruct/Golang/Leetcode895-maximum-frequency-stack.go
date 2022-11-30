package sbgo

type FreqStack struct {
	mx   int
	freq map[int]int
	rec  map[int][]int
}

func max(i, j int) int {
	if i < j {
		return j
	}
	return i
}

func Constructor() FreqStack {
	return FreqStack{0, map[int]int{}, map[int][]int{}}
}

func (this *FreqStack) Push(val int) {
	this.freq[val]++
	this.rec[this.freq[val]] = append(this.rec[this.freq[val]], val)
	this.mx = max(this.mx, this.freq[val])
}

func (this *FreqStack) Pop() int {
	n := len(this.rec[this.mx])
	res := this.rec[this.mx][n-1]
	this.freq[res]--
	this.rec[this.mx] = this.rec[this.mx][:n-1]
	if n-1 == 0 {
		this.mx -= 1
	}
	return res
}
