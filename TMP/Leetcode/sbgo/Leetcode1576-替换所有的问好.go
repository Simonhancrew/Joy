package sbgo

func modifyString(s string) string {
	n, rec := len(s), []byte(s)
	for i := 0; i < n; i++ {
		if rec[i] == '?' {
			for t := byte('a'); t <= 'c'; t++ {
				if (i > 0 && rec[i-1] == t) || (i < n-1 && rec[i+1] == t) {
					continue
				}
				rec[i] = t
				break
			}
		}
	}
	return string(rec)
}
