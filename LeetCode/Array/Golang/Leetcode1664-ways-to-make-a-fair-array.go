package sbgo

func waysToMakeFair(nums []int) int {
	n := len(nums)
	s1, s2 := make([]int, n+1), make([]int, n+1)
	for i := 1; i <= n; i++ {
		s1[i], s2[i] = s1[i-1], s2[i-1]
		if i%2 == 1 {
			s1[i] += nums[i-1]
		} else {
			s2[i] += nums[i-1]
		}
	}
	res := 0
	for i := 1; i <= n; i++ {
		odd, even := s1[i-1]+s2[n]-s2[i], s2[i-1]+s1[n]-s1[i]
		if odd == even {
			res++
		}
	}
	return res
}
