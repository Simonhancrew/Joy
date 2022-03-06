package sbgo

func goodDaysToRobBank(security []int, time int) []int {
	n, ans, cnt := len(security), []int{}, 0
	l, r := make([]int, n), make([]int, n)
	for i := 1; i < n; i++ {
		if security[i] <= security[i-1] {
			cnt++
		} else {
			cnt = 0
		}
		l[i] = cnt
	}
	cnt = 0
	for i := n - 2; i >= 0; i-- {
		if security[i] <= security[i+1] {
			cnt++
		} else {
			cnt = 0
		}
		r[i] = cnt
	}
	for i := 0; i < n; i++ {
		if l[i] >= time && r[i] >= time {
			ans = append(ans, i)
		}
	}
	return ans
}
