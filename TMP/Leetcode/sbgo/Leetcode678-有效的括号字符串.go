package sbgo

func checkValidString(s string) bool {
	cnt1, cnt2 := 0, 0
	for i := 0; i < len(s); i++ {
		if s[i] == '(' {
			cnt1++
			cnt2++
		} else if s[i] == '*' {
			cnt1--
			cnt2++
		} else {
			cnt1--
			cnt2--
		}
		cnt1 = max(cnt1, 0)
		if cnt1 > cnt2 {
			return false
		}
	}
	return cnt1 == 0
}
