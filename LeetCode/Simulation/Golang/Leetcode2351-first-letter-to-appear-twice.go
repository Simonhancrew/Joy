package sbgo

func repeatedCharacter(s string) byte {
	ans, st := byte(0), make([]int, 26)
	for _, x := range s {
		if st[x-'a'] == 1 {
			ans = byte(x)
			break
		}
		st[x-'a']++
	}
	return ans
}
