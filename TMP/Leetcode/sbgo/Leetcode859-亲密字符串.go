package sbgo

func buddyStrings(s string, goal string) bool {
	if len(s) != len(goal) {
		return false
	}
	if s == goal {
		mp := map[rune]int{}
		for _, ch := range s {
			mp[ch]++
			if mp[ch] > 1 {
				return true
			}
		}
		return false
	}
	idx := []int{}
	for i := 0; i < len(s); i++ {
		if goal[i] != s[i] {
			idx = append(idx, i)
		}
	}
	if len(idx) != 2 {
		return false
	}
	x, y := idx[0], idx[1]
	return s[x] == goal[y] && s[y] == goal[x]
}
