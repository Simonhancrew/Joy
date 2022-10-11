package sbgo

func areAlmostEqual(s1 string, s2 string) bool {
	if s1 == s2 {
		return true
	}
	n, rec := len(s1), []int{}
	for i := 0; i < n; i++ {
		if s1[i] != s2[i] {
			rec = append(rec, i)
			if len(rec) > 2 {
				return false
			}
		}
	}
	if len(rec) == 1 {
		return false
	}
	return s1[rec[0]] == s2[rec[1]] && s1[rec[1]] == s2[rec[0]]
}
