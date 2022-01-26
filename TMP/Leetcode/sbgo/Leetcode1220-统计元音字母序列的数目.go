package sbgo

func countVowelPermutation(n int) int {
	const P int64 = 1e9 + 7
	f := make([][]int64, n+1)
	for i := 0; i <= n; i++ {
		f[i] = make([]int64, 5)
	}
	for i := 0; i < 5; i++ {
		f[1][i] = 1
	}
	for i := 2; i <= n; i++ {
		f[i][0] = f[i-1][1]
		f[i][1] = f[i-1][0] + f[i-1][2]
		f[i][2] = f[i-1][0] + f[i-1][1] + f[i-1][3] + f[i-1][4]
		f[i][3] = f[i-1][2] + f[i-1][4]
		f[i][4] = f[i-1][0]
		for j := 0; j < 5; j++ {
			f[i][j] %= P
		}
	}
	ans := int64(0)
	for i := 0; i < 5; i++ {
		ans += f[n][i]
	}
	return int(ans % P)
}
