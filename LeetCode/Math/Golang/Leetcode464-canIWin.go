package sbgo

func canIWin(maxChoosableInteger int, desiredTotal int) bool {
	n, m := maxChoosableInteger, desiredTotal
	if n*(n+1)/2 < m {
		return false
	}
	f := make([]int, 1<<n)
	for i := range f {
		f[i] = -1
	}
	var dp func(int) int
	dp = func(x int) int {
		if f[x] != -1 {
			return f[x]
		}
		sum := 0
		for i := 0; i < n; i++ {
			if (x>>i)&1 == 1 {
				sum += i + 1
			}
		}
		for i := 0; i < n; i++ {
			if (x>>i)&1 == 1 {
				continue
			}
			if sum+i+1 >= m {
				f[x] = 1
				return 1
			}
			if dp(x+(1<<i)) != 1 {
				f[x] = 1
				return 1
			}
		}
		f[x] = 0
		return 0
	}
	res := dp(0)
	if res == 1 {
		return true
	}
	return false
}
