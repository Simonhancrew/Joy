package sbgo

func findKthNumber(m int, n int, k int) int {
	l, r := 1, m*n

	min := func(i, j int) int {
		if i < j {
			return i
		}
		return j
	}

	get := func(mid, m, n int) int {
		res := 0
		for i := 1; i <= n; i++ {
			res += min(m, mid/i)
		}
		return res
	}

	for l < r {
		mid := (l + r) >> 1
		if get(mid, m, n) >= k {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return l
}
