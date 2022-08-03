package sbgo

import "sort"

func orderlyQueue(s string, k int) string {
	if k == 1 {
		res := s
		for i := 0; i < len(s); i++ {
			s = s[1:] + s[0:1]
			if res > s {
				res = s
			}
		}
		return res
	}
	t := []byte(s)
	sort.Slice(t, func(i, j int) bool {
		return t[i] < t[j]
	})
	return string(t)
}
