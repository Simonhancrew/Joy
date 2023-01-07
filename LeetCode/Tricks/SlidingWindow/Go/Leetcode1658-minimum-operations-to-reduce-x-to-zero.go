package sbgo

func minOperations(nums []int, x int) int {
	n, lhs, rhs, ans := len(nums), 0, 0, (1<<31)-1
	for _, x := range nums {
		rhs += x
	}
	if rhs < x {
		return -1
	}
	min := func(i, j int) int {
		if i < j {
			return i
		}
		return j
	}
	for l, r := -1, 0; l < n; l++ {
		if l != -1 {
			lhs += nums[l]
		}
		for r < n && lhs+rhs > x {
			rhs -= nums[r]
			r++
		}
		if lhs+rhs == x {
			ans = min(ans, l+1+n-r)
		}
	}
	if ans == (1<<31)-1 {
		return -1
	}
	return ans
}
