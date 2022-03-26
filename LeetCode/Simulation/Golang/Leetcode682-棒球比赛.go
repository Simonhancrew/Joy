package sbgo

import "strconv"

func calPoints(ops []string) int {
	rec, ans := []int{}, 0
	for _, op := range ops {
		n := len(rec)
		switch op[0] {
		case '+':
			ans += rec[n-1] + rec[n-2]
			rec = append(rec, rec[n-1]+rec[n-2])
		case 'D':
			ans += rec[n-1] * 2
			rec = append(rec, rec[n-1]*2)
		case 'C':
			ans -= rec[n-1]
			rec = rec[:n-1]
		default:
			t, _ := strconv.Atoi(op)
			rec = append(rec, t)
			ans += t
		}
	}
	return ans
}
