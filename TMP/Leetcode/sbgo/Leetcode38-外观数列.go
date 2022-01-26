package sbgo

import (
	"strconv"
	"strings"
)

func countAndSay(n int) string {
	res := "1"
	for i := 0; i < n-1; i++ {
		sb := strings.Builder{}
		for j := 0; j < len(res); j++ {
			k := j
			for k < len(res) && res[k] == res[j] {
				k++
			}
			cnt := k - j
			sb.WriteString(strconv.Itoa(cnt))
			sb.WriteByte(res[j])
			j = k - 1
		}
		res = sb.String()
	}
	return res
}
