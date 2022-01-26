package sbgo

func minMoves(nums []int) int {
	res, m := 0, min(nums)
	for _, i := range nums {
		res += i - m
	}
	return res
}

func min(nums []int) int {
	res := nums[0]
	for i := 1; i < len(nums); i++ {
		if res < nums[i] {
			continue
		} else {
			res = nums[i]
		}
	}
	return res
}
