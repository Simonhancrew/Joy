package sbgo

func findSubstring(s string, words []string) []int {
	n, m, w := len(s), len(words), len(words[0])
	rec := make(map[string]int)
	for _, word := range words {
		rec[word]++
	}
	res := []int{}
	for i := 0; i < w; i++ {
		tmp, cnt := make(map[string]int), 0
		for j := i; j+w <= n; j += w {
			if j >= i+m*w {
				t := s[j-m*w : j-m*w+w]
				tmp[t]--
				if tmp[t] < rec[t] {
					cnt--
				}
			}
			t := s[j : j+w]
			tmp[t]++
			if tmp[t] <= rec[t] {
				cnt++
			}
			if cnt == m {
				res = append(res, j-(m-1)*w)
			}
		}
	}
	return res
}
