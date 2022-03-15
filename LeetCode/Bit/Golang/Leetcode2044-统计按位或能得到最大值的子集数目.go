package sbgo

func countMaxOrSubsets(nums []int) int {
	n, mxor, ans := len(nums), 0, 0
	for i := 1; i < 1<<n; i++ {
		cur := 0
		for j := 0; j < n; j++ {
			if i>>j&1 == 1 {
				cur |= nums[j]
			}
		}
		if cur == mxor {
			ans++
		} else if cur > mxor {
			mxor = cur
			ans = 1
		}
	}
	return ans
}
