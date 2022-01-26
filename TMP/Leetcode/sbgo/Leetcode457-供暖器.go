package sbgo

import (
	"math"
	"sort"
)

func findRadius(houses []int, heaters []int) int {
	sort.Slice(houses, func(i, j int) bool {
		return houses[i] < houses[j]
	})
	sort.Slice(heaters, func(i, j int) bool {
		return heaters[i] < heaters[j]
	})
	check := func(length int) bool {
		for i, j := 0, 0; i < len(houses); i++ {
			for j < len(heaters) && int(math.Abs(float64(heaters[j]-houses[i]))) > length {
				j++
			}
			if j >= len(heaters) {
				return false
			}
		}
		return true
	}
	l, r := 0, int(1e9)
	for l < r {
		mid := (l + r) >> 1
		if check(mid) {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return r
}
