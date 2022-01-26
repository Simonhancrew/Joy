package sbgo

func checkPerfectNumber(num int) bool {
	ans := 0
	for i := 1; i <= num/i; i++ {
		if num%i == 0 {
			if i < num {
				ans += i
			}
			if num/i < num && i != num/i {
				ans += num / i
			}
		}
	}
	return ans == num
}
