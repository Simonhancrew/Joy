package sbgo

import "math"

func oneEditAway(first string, second string) bool {
	n, m := len(first), len(second)
	if math.Abs(float64(n-m)) > 1 {
		return false
	}
	if n > m {
		n, m = m, n
		first, second = second, first
	}
	i, j, cnt := 0, 0, 0
	for i < n && j < m && cnt <= 1 {
		if first[i] == second[j] {
			i, j = i+1, j+1
		} else {
			if n == m {
				i, j, cnt = i+1, j+1, cnt+1
			} else {
				j, cnt = j+1, cnt+1
			}
		}
	}
	return cnt <= 1
}
