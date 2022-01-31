package sbgo

func numberOfSteps(num int) int {
	cnt := 0
	for num != 0 {
		if num&1 != 0 {
			num--
		} else {
			num /= 2
		}
		cnt++
	}
	return cnt
}
