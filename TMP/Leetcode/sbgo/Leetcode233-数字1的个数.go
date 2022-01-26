package sbgo

func countDigitOne(n int) int {
	if n <= 0 {
		return 0
	}
	nums := []int{}
	for n != 0 {
		nums = append(nums, n%10)
		n /= 10
	}
	reverse(nums)
	res := 0
	for i := 0; i < len(nums); i++ {
		cur := nums[i]
		left, right, p := 0, 0, 1
		for j := 0; j < i; j++ {
			left = left*10 + nums[j]
		}
		for j := i + 1; j < len(nums); j++ {
			right = right*10 + nums[j]
			p *= 10
		}
		if cur == 0 {
			res += left * p
		} else if cur == 1 {
			res += left*p + right + 1
		} else {
			res += (left + 1) * p
		}
	}
	return res
}

func reverse(nums []int) {
	for i, j := 0, len(nums)-1; i < j; i, j = i+1, j-1 {
		nums[i], nums[j] = nums[j], nums[i]
	}
}
