package sbgo

import (
	"sort"
	"strconv"
)

func findMinDifference(timePoints []string) int {
	trans := []int{}
	for _, s := range timePoints {
		h, _ := strconv.Atoi(s[0:2])
		m, _ := strconv.Atoi(s[3:])
		trans = append(trans, h*60+m)
	}
	sort.Ints(trans)
	ans, n := int(1e9), len(trans)
	if n > 1440 {
		return 0
	}
	for i := 0; i < n-1; i++ {
		ans = min(ans, trans[i+1]-trans[i])
	}
	ans = min(ans, trans[0]+1440-trans[n-1])
	return ans
}
