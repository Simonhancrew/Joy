package sbgo

func shortestSubarray(nums []int, k int) int {
	n := len(nums)
	s := make([]int, n+1)
	for i := 1; i <= n; i++ {
		s[i] = s[i-1] + nums[i-1]
	}
	res := 1000000
	q := []int{0}
	min := func(i, j int) int {
		if i < j {
			return i
		}
		return j
	}
	for i := 1; i <= n; i++ {
		for len(q) != 0 && s[q[0]]+k <= s[i] {
			res = min(res, i-q[0])
			q = q[1:]
		}
		for len(q) != 0 && s[q[len(q)-1]] >= s[i] {
			q = q[:len(q)-1]
		}
		q = append(q, i)
	}
	if res == 1000000 {
		return -1
	}
	return res
}
