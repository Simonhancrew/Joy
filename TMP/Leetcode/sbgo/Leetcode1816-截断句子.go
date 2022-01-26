package sbgo

func truncateSentence(s string, k int) string {
	res := []byte{}
	for i := 0; i < len(s) && k != 0; i++ {
		if s[i] == ' ' {
			k--
		}
		if k != 0 {
			res = append(res, s[i])
		}
	}
	return string(res)
}
