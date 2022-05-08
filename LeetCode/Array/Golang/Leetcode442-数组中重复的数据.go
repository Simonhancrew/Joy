package sbgo

import "math"

func findDuplicates(nums []int) []int {
	n, ans := len(nums), []int{}
	for i := 0; i < n; i++ {
		x := int(math.Abs(float64(nums[i])))
		if nums[x-1] > 0 {
			nums[x-1] = -nums[x-1]
		} else {
			ans = append(ans, x)
		}
	}
	return ans
}
