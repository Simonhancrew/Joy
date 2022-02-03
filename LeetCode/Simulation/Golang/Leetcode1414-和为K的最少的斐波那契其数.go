package sbgo

func findMinFibonacciNumbers(k int) int {
	f := []int{1, 1}
	pre, aft := 1, 1
	for aft < k {
		t := aft
		aft = aft + pre
		pre = t
		f = append(f, aft)
	}
	cnt := 0
	for i := len(f) - 1; i >= 0; i-- {
		for f[i] <= k {
			k -= f[i]
			cnt++
		}
	}
	return cnt
}
