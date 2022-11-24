package sbgo

func numSubarrayBoundedMax(nums []int, left int, right int) int {
	n := len(nums)
	calcu := func(mx int) int {
		res := 0
		for i := 0; i < n; i++ {
			if nums[i] > mx {
				continue
			}
			j := i + 1
			for j < n && nums[j] <= mx {
				j++
			}
			dis := j - i
			res += dis * (dis + 1) / 2
			i = j
		}
		return res
	}
	return calcu(right) - calcu(left-1)
}
