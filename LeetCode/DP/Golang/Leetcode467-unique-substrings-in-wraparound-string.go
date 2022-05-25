package sbgo

func findSubstringInWraproundString(p string) int {
	mp := map[byte]int{}
	for i := 0; i < len(p); {
		j := i + 1
		for j < len(p) && (p[j]-p[j-1] == 1 || (p[j] == 'a' && p[j-1] == 'z')) {
			j++
		}
		for i < j {
			mp[p[i]] = max(mp[p[i]], j-i)
			i++
		}
	}
	res := 0
	for _, v := range mp {
		res += v
	}
	return res
}

func max(i, j int) int {
	if i < j {
		return j
	}
	return i
}
