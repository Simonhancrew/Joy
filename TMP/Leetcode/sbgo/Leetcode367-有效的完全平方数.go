package sbgo

func isPerfectSquare(num int) bool {
	l, r := 1, num
	for l < r {
		mid := (l + r) >> 1
		if mid*mid >= num {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return l*l == num
}
