package sbgo

func countKDifference(nums []int, k int) int {
	ans, mp := 0, map[int]int{}
	for _, num := range nums {
		if cnt, has := mp[num+k]; has {
			ans += cnt
		}
		if cnt, has := mp[num-k]; has {
			ans += cnt
		}
		mp[num]++
	}
	return ans
}
