package sbgo

import "unicode"

func letterCasePermutation(s string) []string {
	sb, n := []byte(s), len(s)
	ans := []string{}
	var dfs func(i int)
	dfs = func(i int) {
		if i == n {
			ans = append(ans, string(sb))
			return
		}
		dfs(i + 1)
		if !unicode.IsDigit(rune(sb[i])) {
			sb[i] ^= 32
			dfs(i + 1)
			sb[i] ^= 32
		}
	}
	dfs(0)
	return ans
}
