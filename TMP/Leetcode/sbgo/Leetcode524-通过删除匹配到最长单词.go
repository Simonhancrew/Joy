package sbgo

func findLongestWord(s string, dictionary []string) string {
	ans := ""
	for _, x := range dictionary {
		i := 0
		for j := range s {
			if s[j] == x[i] {
				i++
				if i == len(x) {
					if len(x) > len(ans) || len(x) == len(ans) && x < ans {
						ans = x
					}
					break
				}
			}
		}
	}
	return ans
}
