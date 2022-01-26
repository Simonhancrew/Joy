package sbgo

func reverseStr(s string, k int) string {
	bs, n := []byte(s), len(s)
	rev := func(i, j int) {
		for i < j {
			bs[i], bs[j] = bs[j], bs[i]
			i++
			j--
		}
	}
	for i := 0; i < n; i += (2 * k) {
		if i+k <= n {
			rev(i, i+k-1)
		} else {
			rev(i, n-1)
		}
	}
	return string(bs)
}
