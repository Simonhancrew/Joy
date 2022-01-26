package sbgo

import "strconv"

func findNthDigit(n int) int {
	cnt, base, s := 1, 9, 1
	for n > cnt*base {
		n -= base * cnt
		cnt++
		base *= 10
		s *= 10
	}
	s += (n+cnt-1)/cnt - 1
	if n%cnt == 0 {
		n = cnt
	} else {
		n = n % cnt
	}
	return int(strconv.Itoa(s)[n-1] - '0')
}
