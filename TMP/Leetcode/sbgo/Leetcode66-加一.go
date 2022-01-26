package sbgo

func plusOne(digits []int) []int {
	n, car := len(digits), 1
	for i := n - 1; i >= 0; i-- {
		cur := car + digits[i]
		digits[i] = cur % 10
		car = cur / 10
	}
	if car != 0 {
		digits = append([]int{1}, digits...)
	}
	return digits
}
