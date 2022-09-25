package sbgo

import "strconv"

func rotatedDigits(n int) int {
	s := strconv.Itoa(n)
	size := len(s)
	diffs := []int{0, 0, 1, -1, -1, 1, 1, -1, 0, 1}
	f := make([][]int, size)
	for i, _ := range f {
		f[i] = make([]int, 2)
		f[i][0] = -1
		f[i][1] = -1
	}
	var dfs func(pos, diff int, limit bool) int
	dfs = func(pos, diff int, limit bool) int {
		if pos == size {
			return diff
		}
		if !limit && f[pos][diff] != -1 {
			return f[pos][diff]
		}
		res := 0
		up := 9
		if limit {
			up = int(s[pos] - '0')
		}
		for i := 0; i <= up; i++ {
			if diffs[i] == -1 {
				continue
			}
			res += dfs(pos+1, diff|diffs[i], limit && i == up)
		}
		if !limit {
			f[pos][diff] = res
		}
		return res
	}
	return dfs(0, 0, true)
}
