package sbgo

func divide(dividend int, divisor int) int {
	a, b := dividend, divisor
	sign := false
	if (a ^ b) < 0 {
		sign = true
	}
	if a < 0 {
		a = -a
	}
	if b < 0 {
		b = -b
	}
	l, r := 0, a
	for l < r {
		// go里的运算优先级不一样
		mid := (l + r + 1) >> 1
		if mul(mid, b) <= a {
			l = mid
		} else {
			r = mid - 1
		}
	}
	if sign {
		l = -l
	}
	if l > (1<<31)-1 || l < -(1<<31) {
		l = (1 << 31) - 1
	}
	return l
}

func mul(mid, b int) int {
	ans := 0
	for b != 0 {
		if b&1 == 1 {
			ans += mid
		}
		b >>= 1
		mid += mid
	}
	return ans
}
