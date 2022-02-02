package sbgo

import "strings"

func reversePrefix(word string, ch byte) string {
	idx := strings.IndexByte(word, ch)
	if idx >= 0 {
		arr := []byte(word)
		for l := 0; l < idx; l++ {
			arr[l], arr[idx] = arr[idx], arr[l]
			idx--
		}
		word = string(arr)
	}
	return word
}
