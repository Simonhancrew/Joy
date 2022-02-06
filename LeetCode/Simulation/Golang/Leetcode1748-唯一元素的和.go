package sbgo

func sumOfUnique(nums []int) int {
	st, ans := make([]int, 101), 0
	for i := 0; i < len(nums); i++ {
		st[nums[i]]++
	}
	for i := 1; i <= 100; i++ {
		if st[i] == 1 {
			ans += i
		}
	}
	return ans
}
