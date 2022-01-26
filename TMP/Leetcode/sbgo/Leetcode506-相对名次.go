package sbgo

import (
	"sort"
	"strconv"
)

type helper struct {
	score, idx int
}

var rec = [3]string{"Gold Medal", "Silver Medal", "Bronze Medal"}

func findRelativeRanks(score []int) []string {
	n := len(score)
	help := make([]helper, n)
	for i := 0; i < n; i++ {
		help[i].score = score[i]
		help[i].idx = i
	}
	sort.Slice(help, func(i, j int) bool {
		return help[i].score > help[j].score
	})
	res := make([]string, n)
	for i := 0; i < n; i++ {
		if i < 3 {
			res[help[i].idx] = rec[i]
		} else {
			res[help[i].idx] = strconv.Itoa(i + 1)
		}
	}
	return res
}
