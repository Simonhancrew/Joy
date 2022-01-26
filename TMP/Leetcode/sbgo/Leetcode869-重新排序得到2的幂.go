package sbgo

func reorderedPowerOf2(n int) bool {
	const N = 1000000000
	for i := 1; i <= N; i *= 2 {
		if check(i, n) {
			return true
		}
	}
	return false
}

func check(a, b int) bool {
	mp1, mp2 := make([]int, 10), make([]int, 10)
	for a != 0 {
		t := a % 10
		a /= 10
		mp1[t]++
	}
	for b != 0 {
		t := b % 10
		b /= 10
		mp2[t]++
	}
	for i := 0; i <= 9; i++ {
		if mp1[i] != mp2[i] {
			return false
		}
	}
	return true
}
