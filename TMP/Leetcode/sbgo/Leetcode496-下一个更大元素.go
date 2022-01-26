package sbgo

func nextGreaterElement(nums1 []int, nums2 []int) []int {
	n, m := len(nums1), len(nums2)
	lb := make([]int, m)
	stk := []int{}
	for i := m - 1; i >= 0; i-- {
		t := nums2[i]
		for len(stk) != 0 && stk[len(stk)-1] <= t {
			stk = stk[0 : len(stk)-1]
		}
		if len(stk) == 0 {
			lb[i] = -1
		} else {
			lb[i] = stk[len(stk)-1]
		}
		stk = append(stk, t)
	}
	ans := make([]int, n)
	mp := map[int]int{}
	for i := 0; i < m; i++ {
		mp[nums2[i]] = i
	}
	for i := 0; i < n; i++ {
		ans[i] = lb[mp[nums1[i]]]
	}
	return ans
}
