package sbgo

import "strings"

func licenseKeyFormatting(s string, k int) string {
	ans, cnt := []byte{}, 0
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] == '-' {
			continue
		}
		if cnt == k {
			ans = append(ans, '-')
			cnt = 0
		}

		ans = append(ans, s[i])
		cnt++
	}
	reverse(ans)
	return strings.ToUpper(string(ans))
}

// reverse a slice
func reverse(arr []byte) {
	for i, j := 0, len(arr)-1; i < j; i, j = i+1, j-1 {
		arr[i], arr[j] = arr[j], arr[i]
	}
}
