package sbgo

func numberOfArithmeticSlices(nums []int) int {
	n := len(nums)
	if n < 3 {
		return 0
	}
	for i := n - 1; i > 0; i-- {
		nums[i] -= nums[i-1]
	}
	res := 0
	for i := 1; i < n; i++ {
		j := i
		for j < n && nums[j] == nums[i] {
			j++
		}
		k := j - i
		res += (k - 1) * k / 2
		i = j - 1
	}
	return res
}
