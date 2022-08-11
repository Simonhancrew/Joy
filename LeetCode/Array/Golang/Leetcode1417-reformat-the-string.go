package sbgo

import "unicode"

func reformat(s string) string {
	cnt, n := 0, len(s)
	for _, ch := range s {
		if unicode.IsDigit(ch) {
			cnt++
		}
	}
	if abs(cnt+cnt-n) > 1 {
		return ""
	}
	flag := cnt > (n - cnt)
	arr := []byte(s)
	for i, j := 0, 1; i < n; i += 2 {
		if unicode.IsDigit(rune(arr[i])) != flag {
			for unicode.IsDigit(rune(arr[j])) != flag {
				j += 2
			}
			arr[i], arr[j] = arr[j], arr[i]
		}
	}
	return string(arr)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
