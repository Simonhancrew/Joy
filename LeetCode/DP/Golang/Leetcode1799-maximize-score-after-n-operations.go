package sbgo

func maxScore(nums []int) int {
	n := len(nums)
	f := make([]int, 1<<n)
	max := func(i, j int) int {
		if i < j {
			return j
		}
		return i
	}
	var gcd func(i, j int) int
	gcd = func(a, b int) int {
		if b == 0 {
			return a
		}
		return gcd(b, a%b)
	}

	for i := 0; i < (1 << n); i++ {
		cnt := 0
		for j := 0; j < n; j++ {
			if (i>>j)&1 == 0 {
				cnt++
			}
		}
		if cnt&1 == 1 {
			continue
		}
		cnt = cnt/2 + 1
		for j := 0; j < n; j++ {
			if (i>>j)&1 == 1 {
				for k := j + 1; k < n; k++ {
					if (i>>k)&1 == 1 {
						f[i] = max(f[i], f[i-(1<<k)-(1<<j)]+gcd(nums[j], nums[k])*cnt)
					}
				}
			}
		}
	}
	return f[(1<<n)-1]
}
