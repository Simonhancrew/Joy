package sbgo

func countBalls(lowLimit int, highLimit int) int {
	ans, mp := 0, make(map[int]int)
	calcu := func(x int) int {
		res := 0
		for x != 0 {
			res += x % 10
			x /= 10
		}
		return res
	}
	for i := lowLimit; i <= highLimit; i++ {
		mp[calcu(i)]++
	}
	max := func(i, j int) int {
		if i < j {
			return j
		}
		return i
	}
	for _, item := range mp {
		ans = max(ans, item)
	}
	return ans
}
