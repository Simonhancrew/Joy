package sbgo

func maxValue(n int, index int, maxSum int) int {
	l, r := 1, maxSum
	calcu := func(mx, leng int) int {
		if leng+1 < mx {
			mn := mx - leng
			return (mx - 1 + mn) * leng / 2
		}
		cnt := leng - mx + 1
		return (mx-1)*mx/2 + cnt
	}
	check := func(mid, index, n, maxSum int) bool {
		lhs_len, rhs_len := index, n-1-index
		return mid+calcu(mid, lhs_len)+calcu(mid, rhs_len) <= maxSum
	}
	for l < r {
		mid := (l + r + 1) >> 1
		if check(mid, index, n, maxSum) {
			l = mid
		} else {
			r = mid - 1
		}
	}
	return l
}
