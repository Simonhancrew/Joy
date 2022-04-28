package sbgo

func sortArrayByParity(nums []int) []int {
	l, r := 0, len(nums)-1
	for l < r {
		for l < r && nums[l]%2 == 0 {
			l++
		}
		for l < r && nums[r]%2 == 1 {
			r--
		}
		nums[l], nums[r] = nums[r], nums[l]
		l++
		r--
	}
	return nums
}
