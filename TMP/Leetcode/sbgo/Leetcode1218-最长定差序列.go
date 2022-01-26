package sbgo

func longestSubsequence(arr []int, difference int) int {
	f := map[int]int{}
	ans := 1
	for _, a := range arr {
		t, err := f[a-difference]
		if err {
			f[a] = t + 1
		} else {
			f[a] = 1
		}
		ans = max(ans, f[a])
	}
	return ans
}

func max(i, j int) int {
	if i < j {
		return j
	}
	return i
}
