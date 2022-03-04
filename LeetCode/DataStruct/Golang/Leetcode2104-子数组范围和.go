package sbgo

func subArrayRanges(nums []int) int64 {
	res, n := int64(0), len(nums)
	for i := 0; i < n; i++ {
		mx, mn := nums[i], nums[i]
		for j := i + 1; j < n; j++ {
			if nums[j] > mx {
				mx = nums[j]
			}
			if nums[j] < mn {
				mn = nums[j]
			}

			res += (int64)(mx - mn)
		}
	}
	return res
}
