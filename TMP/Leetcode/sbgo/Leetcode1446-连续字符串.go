package sbgo

func maxPower(s string) int {
	res := 0
	for i, j := 0, 0; i < len(s); i++ {
		for j < len(s) && s[i] == s[j] {
			j++
		}
		res = max(res, j-i)
		i = j - 1
	}
	return res
}
