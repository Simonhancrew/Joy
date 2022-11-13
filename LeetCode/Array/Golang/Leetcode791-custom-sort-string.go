package sbgo

import "sort"

func customSortString(order string, s string) string {
	as := []byte(s)
	pa := make([]int, 26)
	for i := 0; i < 26; i++ {
		pa[i] = 26
	}
	for i := 0; i < len(order); i++ {
		pa[order[i]-'a'] = i
	}
	sort.Slice(as, func(i, j int) bool {
		return pa[as[i]-'a'] < pa[as[j]-'a']
	})
	return string(as)
}
