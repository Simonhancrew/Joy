package sbgo

func distinctSubseqII(s string) int {
	MOD, n := int(1e9)+7, len(s)
	f := make([][]int, n+1)
	for i := 0; i <= n; i++ {
		f[i] = make([]int, 26)
	}
	for i := 0; i < n; i++ {
		f[i+1][s[i]-'a'] = 1
		for j := 0; j < 26; j++ {
			f[i+1][s[i]-'a'] = (f[i+1][s[i]-'a'] + f[i][j]) % MOD
			if int(s[i]-'a') != j {
				f[i+1][j] = (f[i+1][j] + f[i][j]) % MOD
			}
		}
	}
	res := 0
	for _, x := range f[n] {
		res = (res + x) % MOD
	}
	return res
}
