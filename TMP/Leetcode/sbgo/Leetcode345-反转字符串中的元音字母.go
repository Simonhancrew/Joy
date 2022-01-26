package sbgo

func reverseVowels(s string) string {
	bs := []byte(s)
	rec := map[byte]bool{'a': true, 'e': true, 'i': true, 'o': true, 'u': true, 'A': true, 'E': true, 'I': true, 'O': true, 'U': true}
	i, j := 0, len(s)-1
	for i < j {
		for i < j && !rec[bs[i]] {
			i++
		}
		for i < j && !rec[bs[j]] {
			j--
		}
		if i < j {
			bs[i], bs[j] = bs[j], bs[i]
			i++
			j--
		}
	}
	return string(bs)
}
