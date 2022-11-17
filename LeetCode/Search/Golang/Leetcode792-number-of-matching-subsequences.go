package sbgo

import "sort"

func numMatchingSubseq(s string, words []string) int {
	mp, n := [26][]int{}, len(s)
	for i := 0; i < n; i++ {
		mp[s[i]-'a'] = append(mp[s[i]-'a'], i)
	}
	ans := len(words)
	for _, x := range words {
		if len(x) > len(s) {
			ans--
			break
		}
		idx := -1
		for _, c := range x {
			arr := mp[c-'a']
			p := sort.SearchInts(arr, idx+1)
			if p == len(arr) {
				ans--
				break
			}
			idx = arr[p]
		}
	}
	return ans
}
