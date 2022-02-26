package sbgo

func maximumDifference(nums []int) int {
	ans, n, mn := -1, len(nums), nums[0]
	for i := 1; i < n; i++ {
		if nums[i] > mn {
			if ans < nums[i]-mn {
				ans = nums[i] - mn
			}
		} else {
			mn = nums[i]
		}
	}
	return ans
}
