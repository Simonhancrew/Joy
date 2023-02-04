package sbgo

import "sort"

func getMaximumConsecutive(coins []int) int {
	sort.Ints(coins)
	ans := 0
	for _, c := range coins {
		if c > ans+1 {
			return ans + 1
		}
		ans += c
	}
	return ans + 1
}
