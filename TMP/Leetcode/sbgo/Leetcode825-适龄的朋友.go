package sbgo

func numFriendRequests(ages []int) int {
	n := len(ages)
	res := n * n
	cnt := make([]int, 121)
	for _, age := range ages {
		cnt[age]++
	}
	for i := 1; i <= 120; i++ {
		for j := 1; j <= 120; j++ {
			if j > i || 2*j <= i+14 {
				res -= cnt[i] * cnt[j]
			} else if j == i {
				res -= cnt[i]
			}
		}
	}
	return res
}
