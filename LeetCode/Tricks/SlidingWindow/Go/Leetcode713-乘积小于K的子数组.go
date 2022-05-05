package sbgo

func numSubarrayProductLessThanK(nums []int, k int) int {
	res, acc, n := 0, 1, len(nums)
	for i, j := 0, 0; j < n; j++ {
		acc *= nums[j]
		for i <= j && acc >= k {
			acc /= nums[i]
			i++
		}
		res += j - i + 1
	}
	return res
}
