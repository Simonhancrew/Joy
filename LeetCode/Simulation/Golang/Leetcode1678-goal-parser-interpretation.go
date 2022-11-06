package sbgo

func interpret(s string) string {
	res, n := "", len(s)
	for i := 0; i < n; i++ {
		if s[i] == 'G' {
			res += "G"
		} else {
			j := i
			for s[j] != ')' {
				j++
			}
			if j-i <= 1 {
				res += "o"
			} else {
				res += "al"
			}
			i = j
		}
	}
	return res
}
