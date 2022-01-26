package sbgo

func chalkReplacer(chalk []int, k int) int {
	sum, n, res := 0, len(chalk), -1
	for _, val := range chalk {
		sum += val
	}
	k = k % sum
	for i := 0; i < n; i++ {
		if chalk[i] > k {
			res = i
			break
		} else {
			k -= chalk[i]
		}
	}
	return res
}
