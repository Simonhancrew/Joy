package sbgo

import "sort"

func canReorderDoubled(arr []int) bool {
	mp := make(map[int]int)
	for _, num := range arr {
		mp[num]++
	}
	rec := []int{}
	for k, _ := range mp {
		rec = append(rec, k)
	}
	sort.Slice(rec, func(i, j int) bool {
		return abs(rec[i]) < abs(rec[j])
	})
	for _, k := range rec {
		if mp[k*2] < mp[k] {
			return false
		}
		mp[k*2] -= mp[k]
	}
	return true
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
