package sbgo

func totalMoney(n int) int {
	ans, cnt := 0, 1
	for i := 0; i < n; i++ {
		if i != 0 && i%7 == 0 {
			cnt++
		}
		ans += (cnt + i%7)
	}
	return ans
}
