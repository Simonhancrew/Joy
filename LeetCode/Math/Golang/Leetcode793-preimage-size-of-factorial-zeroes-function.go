package sbgo

func preimageSizeFZF(k int) int {
	f := func(x int) int {
		res := 0
		for x > 0 {
			res += x / 5
			x /= 5
		}
		return res
	}

	calcu := func(k int) int {
		l, r := -1, int(1e18)
		for l < r {
			mid := (l + r + 1) >> 1
			if f(mid) <= k {
				l = mid
			} else {
				r = mid - 1
			}
		}
		return r
	}

	return calcu(k) - calcu(k-1)
}
