package sbgo

import "sort"

func nextGreatestLetter(letters []byte, target byte) byte {
	l, r := 0, len(letters)-1
	sort.Slice(letters, func(i, j int) bool {
		return letters[i] < letters[j]
	})
	for l < r {
		mid := (l + r + 1) >> 1
		if letters[mid] <= target {
			l = mid
		} else {
			r = mid - 1
		}
	}
	if letters[r] <= target {
		r += 1
	}
	if r == len(letters) {
		r = 0
	}
	return letters[r]
}
