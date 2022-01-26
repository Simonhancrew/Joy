package sbgo

func lengthOfLastWord(s string) int {
	idx := len(s) - 1
	for idx >= 0 && s[idx] == ' ' {
		idx--
	}
	r := idx
	for idx >= 0 && s[idx] != ' ' {
		idx--
	}
	l := idx
	return r - l
}
