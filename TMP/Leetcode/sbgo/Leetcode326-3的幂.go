package sbgo

/*
func isPowerOfThree(n int) bool {
	if n == 0 {
		return false
	}
	for n%3 == 0 {
		n /= 3
	}
	return n == 1
}
*/

func isPowerOfThree(n int) bool {
	return n > 0 && qmi(3, 19)%n == 0
}

func qmi(base, p int) int {
	res := 1
	for p != 0 {
		if p&1 == 1 {
			res *= base
		}
		base *= base
		p >>= 1
	}
	return res
}
