package sbgo

func minStickers(stickers []string, target string) int {
	n := len(target)
	f := make([]int, 1<<n)
	for i := 0; i < len(f); i++ {
		f[i] = -1
	}
	var dp func(int) int
	dp = func(st int) int {
		if f[st] != -1 {
			return f[st]
		}
		if st == 1<<n-1 {
			return 0
		}
		f[st] = n + 1
		for _, s := range stickers {
			t, cnt := st, make([]int, 26)
			for _, c := range s {
				cnt[c-'a']++
			}
			for i := 0; i < len(target); i++ {
				if (t>>i)&1 == 0 && cnt[target[i]-'a'] > 0 {
					cnt[target[i]-'a']--
					t += 1 << i
				}
			}
			if t != st {
				f[st] = min(f[st], dp(t)+1)
			}
		}
		return f[st]
	}
	res := dp(0)
	if res >= n+1 {
		return -1
	}
	return res
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}
