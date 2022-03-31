package sbgo

func selfDividingNumbers(left int, right int) []int {
	res := []int{}
	check := func(num int) bool {
		tmp := num
		for tmp != 0 {
			t := tmp % 10
			tmp /= 10
			if t == 0 || num%t != 0 {
				return false
			}
		}
		return true
	}
	for i := left; i <= right; i++ {
		if check(i) {
			res = append(res, i)
		}
	}
	return res
}
