package sbgo

func largestSumOfAverages(nums []int, k int) float64 {
	n := len(nums)
	f, s := make([][]float64, n+1), make([]int, n+1)
	f[0] = make([]float64, k+1)
	for i := 1; i <= k; i++ {
		f[0][i] = -100000
	}
	for i := 1; i <= n; i++ {
		s[i] = s[i-1] + nums[i-1]
		f[i] = make([]float64, k+1)
		for j := 0; j <= k; j++ {
			f[i][j] = -100000
		}
	}
	max := func(i, j float64) float64 {
		if i < j {
			return j
		}
		return i
	}
	for i := 1; i <= n; i++ {
		for j := 1; j <= k; j++ {
			for q := 0; q < i; q++ {
				f[i][j] = max(f[i][j], f[q][j-1]+float64(s[i]-s[q])/float64(i-q))
			}
		}
	}
	return f[n][k]
}
