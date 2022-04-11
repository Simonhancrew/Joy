package sbgo

func countNumbersWithUniqueDigits(n int) int {
	if n == 0 {
		return 1
	}
	if n == 1 {
		return 10
	}
	base, mul, res := 9, 9, 10
	for i := 0; i < n-1; i++ {
		base *= (mul - i)
		res += base
	}
	return res
}
