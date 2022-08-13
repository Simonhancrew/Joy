package sbgo

import "sort"

func maxChunksToSorted(arr []int) int {
	b, mp := []int{}, map[int]int{}
	b = append(b, arr...)
	sort.Ints(b)
	res, n := 0, len(arr)
	for i, s := 0, 0; i < n; i++ {
		if mp[arr[i]] == 1 {
			s--
		} else if mp[arr[i]] == 0 {
			s++
		}
		mp[arr[i]]--
		if mp[b[i]] == -1 {
			s--
		} else if mp[b[i]] == 0 {
			s++
		}
		mp[b[i]]++
		if s == 0 {
			res++
		}
	}
	return res
}
