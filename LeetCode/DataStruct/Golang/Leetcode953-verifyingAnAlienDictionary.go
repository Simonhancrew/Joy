package sbgo

func isAlienSorted(words []string, order string) bool {
	n, mp := len(order), map[byte]int{}
	for i := 0; i < n; i++ {
		mp[order[i]] = i
	}
	for i := 1; i < len(words); i++ {
		l, r := words[i-1], words[i]
		x, y := 0, 0
		for x < len(l) && y < len(r) {
			if mp[l[x]] > mp[r[y]] {
				return false
			}
			if mp[l[x]] < mp[r[y]] {
				break
			}
			x++
			y++
		}
		if x < len(l) && y == len(r) {
			return false
		}
	}
	return true
}
