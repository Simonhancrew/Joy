package sbgo

func superPow(a int, b []int) int {
	p := 1337
	qmi := func(a, b int) int {
		a %= p
		res := 1
		for b != 0 {
			if b&1 == 1 {
				res = res * a % p
			}
			b >>= 1
			a = a * a % p
		}
		return res
	}
	if len(b) == 0 {
		return 1
	}
	k := b[len(b)-1]
	b = b[:len(b)-1]
	return qmi(superPow(a, b), 10) * qmi(a, k) % p
}
