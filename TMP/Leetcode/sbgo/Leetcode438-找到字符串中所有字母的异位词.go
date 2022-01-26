package sbgo

func findAnagrams(s string, p string) []int {
	mp := map[byte]int{}
	for _, ch := range p {
		mp[byte(ch)]++
	}
	res := []int{}
	n, m, tot := len(s), len(p), len(mp)
	for i, j, sa := 0, 0, 0; j < n; j++ {
		if _, ok := mp[s[j]]; ok {
			mp[s[j]]--
			if mp[s[j]] == 0 {
				sa++
			}
		}
		if j-i+1 == m {
			if sa == tot {
				res = append(res, i)
			}
			if _, ok := mp[s[i]]; ok {
				if mp[s[i]] == 0 {
					sa--
				}
				mp[s[i]]++
			}
			i++
		}
	}
	return res
}
