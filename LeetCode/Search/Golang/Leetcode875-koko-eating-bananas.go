package sbgo

func minEatingSpeed(piles []int, h int) int {
	l, r := 1, -1
	for _, pile := range piles {
		if pile > r {
			r = pile
		}
	}

	check := func(k int) bool {
		cnt := 0
		for _, pile := range piles {
			cnt += (pile + k - 1) / k
		}
		return cnt <= h
	}

	for l < r {
		mid := l + (r-l)/2
		if check(mid) {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return l
}
