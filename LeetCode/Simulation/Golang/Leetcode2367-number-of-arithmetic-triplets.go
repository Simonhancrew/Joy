package sbgo

func arithmeticTriplets(nums []int, diff int) int {
	mp := map[int]bool{}
	for _, x := range nums {
		mp[x] = true
	}
	ans := 0
	for _, x := range nums {
		if mp[x+diff] && mp[x+2*diff] {
			ans++
		}
	}
	return ans
}
