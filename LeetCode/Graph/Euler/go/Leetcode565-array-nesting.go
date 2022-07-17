package sbgo

func arrayNesting(nums []int) int {
	n, ans := len(nums), 0
	for i := 0; i < n; i++ {
		if nums[i] == -1 {
			continue
		}
		ne, cur := i, 0
		for nums[ne] != -1 {
			cur++
			t := ne
			ne = nums[ne]
			nums[t] = -1
		}
		if ans < cur {
			ans = cur
		}
	}
	return ans
}
