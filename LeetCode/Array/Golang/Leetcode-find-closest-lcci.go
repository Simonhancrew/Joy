package sbgo

import "math"

func findClosest(words []string, word1 string, word2 string) int {
	l, r, n := -1, -1, len(words)
	ans := 100000
	for i := 0; i < n; i++ {
		if words[i] == word1 {
			l = i
		}
		if words[i] == word2 {
			r = i
		}
		if l >= 0 && r >= 0 {
			ans = min(ans, int(math.Abs(float64(r-l))))
		}
	}
	return ans
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}
