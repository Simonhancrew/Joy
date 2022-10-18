package sbgo

import "strconv"

// dp(idx, 未定参数，一般描pre, limit, lead)
// 不贴上界，且无前导零的状态才可以复用，此时毫无限制，且可能经历多次
// 这里用前导零判断最终结束的时候是不是一种合法方案，结束的时候都有前导零说明全0

func atMostNGivenDigitSet(digits []string, n int) int {
	s := strconv.Itoa(n)
	m := len(s)
	f := make([]int, m)
	for i := 0; i < m; i++ {
		f[i] = -1
	}
	var dfs func(idx int, limit bool) int
	dfs = func(idx int, limit bool) int {
		if idx == m {
			if limit {
				return 0
			}
			return 1
		}
		if !limit && f[idx] != -1 {
			return f[idx]
		}
		res := 0
		up := byte('9')
		if limit {
			up = s[idx]
		}
		for _, d := range digits {
			if d[0] > up {
				break
			}
			res += dfs(idx+1, limit && d[0] == up)
		}
		if !limit {
			f[idx] = res
		}
		return res
	}
	return dfs(0, true)
}
