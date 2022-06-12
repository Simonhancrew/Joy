package sbgo

func findAndReplacePattern(words []string, pattern string) []string {
	ans, n := []string{}, len(pattern)
	for _, s := range words {
		if len(s) != n {
			continue
		}
		mp, vis, ok := make([]int, 26), make([]int, 26), true
		for i := 0; i < 26; i++ {
			mp[i] = -1
		}
		for i := 0; i < n; i++ {
			l, r := int(s[i]-'a'), int(pattern[i]-'a')
			if mp[l] == -1 && vis[r] == 0 {
				mp[l] = r
				vis[r] = 1
			} else if mp[l] != r {
				ok = false
				break
			}
		}
		if ok {
			ans = append(ans, s)
		}
	}
	return ans
}
