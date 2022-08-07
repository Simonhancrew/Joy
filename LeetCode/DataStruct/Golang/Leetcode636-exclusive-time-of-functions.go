package sbgo

import (
	"strconv"
	"strings"
)

func exclusiveTime(n int, logs []string) []int {
	ans, stk, last := make([]int, n), []int{}, 0
	for _, log := range logs {
		pii := strings.Split(log, ":")
		idx, _ := strconv.Atoi(pii[0])
		tp := pii[1]
		ts, _ := strconv.Atoi(pii[2])
		if tp == "start" {
			if len(stk) > 0 {
				ans[stk[len(stk)-1]] += ts - last
			}
			stk = append(stk, idx)
			last = ts
		} else {
			ans[stk[len(stk)-1]] += ts - last + 1
			last = ts + 1
			stk = stk[:len(stk)-1]
		}
	}
	return ans
}
