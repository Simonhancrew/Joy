package sbgo

func shortestToChar(s string, c byte) []int {
	n := len(s)
	res := make([]int, n)
	for i := range res {
		res[i] = 100000
	}

	for i, j := 0, -1; i < n; i++ {
		if s[i] == c {
			j = i
		}
		if j != -1 {
			res[i] = i - j
		}
	}
	for i, j := n-1, -1; i >= 0; i-- {
		if s[i] == c {
			j = i
		}
		if j != -1 {
			res[i] = min(res[i], j-i)
		}
	}
	return res
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}
