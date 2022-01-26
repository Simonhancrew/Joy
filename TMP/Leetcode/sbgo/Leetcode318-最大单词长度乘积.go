package sbgo

func maxProduct(words []string) int {
	n := len(words)
	bitmask := make([]int, n)
	for i := 0; i < n; i++ {
		for _, ch := range words[i] {
			t := ch - 'a'
			bitmask[i] |= 1 << t
		}
	}
	res := 0
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if bitmask[i]&bitmask[j] == 0 {
				res = max(res, len(words[i])*len(words[j]))
			}
		}
	}
	return res
}
