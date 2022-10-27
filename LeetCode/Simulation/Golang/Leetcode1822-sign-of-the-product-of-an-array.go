package sbgo

func arraySign(nums []int) int {
	nag, n := 0, len(nums)
	for i := 0; i < n; i++ {
		if nums[i] == 0 {
			return 0
		}
		if nums[i] < 0 {
			nag++
		}
	}
	if nag%2 == 1 {
		return -1
	}
	return 1
}
