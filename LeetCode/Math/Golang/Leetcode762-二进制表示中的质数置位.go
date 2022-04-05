package sbgo

func countPrimeSetBits(left int, right int) int {
	st, primes := make([]bool, 33), []int{}
	get_primes := func(n int) {
		st[1] = true
		for i := 2; i <= n; i++ {
			if !st[i] {
				primes = append(primes, i)
			}
			for j := 0; primes[j] <= n/i; j++ {
				st[primes[j]*i] = true
				if i%primes[j] == 0 {
					break
				}
			}
		}
	}
	get_primes(32)
	ans := 0
	check := func(n int) bool {
		cnt := 0
		for n != 0 {
			cnt++
			n -= (n & -n)
		}
		return !st[cnt]
	}
	for i := left; i <= right; i++ {
		if check(i) {
			ans++
		}
	}
	return ans
}
