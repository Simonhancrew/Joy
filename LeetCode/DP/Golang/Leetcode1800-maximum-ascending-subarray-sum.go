package sbgo

func maxAscendingSum(nums []int) int {
	n := len(nums)
	f, ans := make([]int, n), nums[0]
	f[0] = nums[0]
	for i := 1; i < n; i++ {
		if nums[i] > nums[i-1] {
			f[i] = f[i-1] + nums[i]
		} else {
			f[i] = nums[i]
		}
		if ans < f[i] {
			ans = f[i]
		}
	}
	return ans
}
