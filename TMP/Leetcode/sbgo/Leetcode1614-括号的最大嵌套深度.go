package sbgo

func maxDepth(s string) int {
	ans := 0
	for i, cnt := 0, 0; i < len(s); i++ {
		if s[i] == '(' {
			cnt++
			if ans < cnt {
				ans = cnt
			}
		} else if s[i] == ')' {
			cnt--
		}
	}
	return ans
}
