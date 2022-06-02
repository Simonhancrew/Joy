package sbgo

func consecutiveNumbersSum(n int) int {
	n *= 2
	res := 0
	for b := 1; b <= n/b; b++ {
		if n%b == 0 {
			if (n/b-b+1)%2 == 0 {
				res++
			}
		}
	}
	return res
}
