package sbgo

import "math"

func largestPalindrome(n int) int {
	if n == 1 {
		return 9
	}
	base := int(math.Pow10(n) - 1)

	for x := base; ; x-- {
		p := x
		for y := x; y != 0; y /= 10 {
			p = p*10 + y%10
		}

		for y := base; y >= p/y; y-- {
			if p%y == 0 {
				return p % 1337
			}
		}
	}
}
