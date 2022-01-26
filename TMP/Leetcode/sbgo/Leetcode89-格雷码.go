package sbgo

func grayCode(n int) []int {
	ans := []int{0}
	for n != 0 {
		t := len(ans)
		for i := t - 1; i >= 0; i-- {
			ans[i] <<= 1
			ans = append(ans, ans[i]+1)
		}
		n--
	}
	return ans
}
