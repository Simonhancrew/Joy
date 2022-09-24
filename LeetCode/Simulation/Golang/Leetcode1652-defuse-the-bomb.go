package sbgo

func decrypt(code []int, k int) []int {
	n := len(code)
	ans := make([]int, n)
	if k == 0 {
		return ans
	}
	for i := 0; i < n; i++ {
		if k > 0 {
			acc := 0
			for j := i + 1; j <= i+k; j++ {
				acc += code[j%n]
			}
			ans[i] = acc
		} else {
			var acc int = 0
			for j := i - 1; j >= i+k; j-- {
				acc += code[(j+n)%n]
			}
			ans[i] = acc
		}
	}
	return ans
}
