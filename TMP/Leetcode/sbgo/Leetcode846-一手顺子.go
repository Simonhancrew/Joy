package sbgo

import "sort"

func isNStraightHand(hand []int, groupSize int) bool {
	st, n := map[int]int{}, len(hand)
	if n%groupSize != 0 {
		return false
	}
	sort.Ints(hand)
	for _, hd := range hand {
		st[hd]++
	}
	for _, hd := range hand {
		if st[hd] == 0 {
			continue
		}
		for i := hd; i < hd+groupSize; i++ {
			if st[i] == 0 {
				return false
			}
			st[i]--
		}
	}
	return true
}
