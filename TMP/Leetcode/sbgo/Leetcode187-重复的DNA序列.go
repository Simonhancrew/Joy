package sbgo

func findRepeatedDnaSequences(s string) []string {
	n := len(s)
	ans := []string{}
	if n < 10 {
		return ans
	}
	mp := map[string]int{}
	for i := 0; i <= n-10; i++ {
		cur := s[i : i+10]
		mp[cur]++
		if mp[cur] == 2 {
			ans = append(ans, cur)
		}
	}
	return ans
}
