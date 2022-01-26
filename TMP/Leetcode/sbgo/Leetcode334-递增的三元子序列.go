package sbgo

func increasingTriplet(nums []int) bool {
	const INF = int(^uint(0) >> 1)
	f := []int{INF, INF}
	for _, num := range nums {
		k := 2
		for k > 0 && f[k-1] >= num {
			k--
		}
		if k == 2 {
			return true
		}
		f[k] = num
	}
	return false
}
