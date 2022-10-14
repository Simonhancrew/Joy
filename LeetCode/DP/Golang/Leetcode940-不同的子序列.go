package sbgo

func distinctSubseqII(s string) int {
	MOD, n := int(1e9)+7, len(s)
	f := make([]int, 26)
	f[s[0]-'a'] = 1
	sum := func(arr []int) int {
		res := 0
		for _, val := range arr {
			res = (res + val) % MOD
		}
		return res
	}
	for i := 1; i < n; i++ {
		rec := 0
		rec = sum(f) + 1
		f[s[i]-'a'] = rec
	}
	return sum(f)
}
