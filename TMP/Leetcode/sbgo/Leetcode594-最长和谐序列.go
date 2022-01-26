package sbgo

func findLHS(nums []int) (res int) {
	mp := map[int]int{}
	for _, x := range nums {
		mp[x]++
	}
	for k, v := range mp {
		if _, ok := mp[k-1]; ok {
			res = max(res, mp[k-1]+v)
		}
	}
	return
}
