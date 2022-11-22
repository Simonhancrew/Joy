package sbgo

func nthMagicalNumber(n int, a int, b int) int {
	l, r, MOD := 0, int(4e13), int(1e9+7)
	var gcd func(a, b int) int
	gcd = func(a, b int) int {
		if b == 0 {
			return a
		}
		return gcd(b, a%b)
	}
	get := func(mid, a, b int) int {
		return mid/a + mid/b - mid/(a*b/gcd(a, b))
	}
	for l < r {
		mid := (l + r) >> 1
		if get(mid, a, b) >= n {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return l % MOD
}
