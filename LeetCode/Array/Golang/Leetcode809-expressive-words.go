package sbgo

func expressiveWords(s string, words []string) int {
	n, rec := len(s), [][]int{}
	for i := 0; i < n; i++ {
		j := i + 1
		for j < n && s[i] == s[j] {
			j++
		}
		rec = append(rec, []int{int(s[i] - 'a'), j - i})
		i = j - 1
	}
	ans := 0
	check := func(w string) bool {
		if len(w) > len(s) {
			return false
		}
		k, n := 0, len(w)
		for i := 0; i < n; i++ {
			if k == len(rec) {
				return false
			}
			if int(w[i]-'a') != rec[k][0] {
				return false
			}
			j := i + 1
			for j < n && w[j] == w[i] {
				j++
			}
			difs, difw := rec[k][1], j-i
			if difw > difs {
				return false
			}
			if difs < 3 && difw != difs {
				return false
			}
			i, k = j-1, k+1
		}
		return k == len(rec)
	}
	for _, w := range words {
		if check(w) {
			ans++
		}
	}
	return ans
}
