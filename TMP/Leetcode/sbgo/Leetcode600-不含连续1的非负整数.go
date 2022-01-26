package sbgos

func findIntegers(n int) int {
	num := []int{}
	for n != 0 {
		num = append(num, n&1)
		n >>= 1
	}
	dp := make([][]int, len(num)+1)
	for i := range dp {
		dp[i] = make([]int, 2)
	}
	dp[1][0], dp[1][1] = 1, 1
	for i := 2; i <= len(num); i++ {
		dp[i][0] = dp[i-1][1] + dp[i-1][0]
		dp[i][1] = dp[i-1][0]
	}
	res, last := 0, 0
	for i := len(num); i != 0; i-- {
		if num[i-1] == 1 {
			res += dp[i][0]
			if last == 1 {
				return res
			}
		}
		last = num[i-1]
	}
	return res + 1
}
