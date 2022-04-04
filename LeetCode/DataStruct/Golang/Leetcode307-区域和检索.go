package sbgo

type NumArray struct {
	tr []int
	n  int
}

func lowbit(x int) int {
	return x & (-x)
}

func add(tr []int, x, k, n int) {
	for i := x; i <= n; i += lowbit(i) {
		tr[i] += k
	}
}

func ask(tr []int, x, n int) int {
	sum := 0
	for i := x; i != 0; i -= lowbit(i) {
		sum += tr[i]
	}
	return sum
}

func Constructor(nums []int) NumArray {
	n := len(nums)
	tr := make([]int, n+1)

	for i := 0; i < n; i++ {
		add(tr, i+1, nums[i], n)
	}
	return NumArray{tr, n}
}

func (this *NumArray) Update(index int, val int) {
	pre := ask(this.tr, index+1, this.n) - ask(this.tr, index, this.n)
	ch := val - pre
	add(this.tr, index+1, ch, this.n)
}

func (this *NumArray) SumRange(left int, right int) int {
	return ask(this.tr, right+1, this.n) - ask(this.tr, left, this.n)
}
