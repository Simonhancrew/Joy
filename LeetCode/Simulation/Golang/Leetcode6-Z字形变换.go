package sbgo

import "strings"

func convert(s string, numRows int) string {
	if numRows == 1 {
		return s
	}
	sb := &strings.Builder{}
	for i := 0; i < numRows; i++ {
		if i == 0 || i == numRows-1 {
			for j := i; j < len(s); j += 2*numRows - 2 {
				sb.WriteByte(s[j])
			}
		} else {
			for j, k := i, 2*numRows-2-i; j < len(s) || k < len(s); j, k = j+2*numRows-2, k+2*numRows-2 {
				if j < len(s) {
					sb.WriteByte(s[j])
				}
				if k < len(s) {
					sb.WriteByte(s[k])
				}
			}
		}
	}
	return sb.String()
}
