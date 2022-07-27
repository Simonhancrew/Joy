package sbgo

import (
	"fmt"
	"unicode"
)

func fractionAddition(expression string) string {
	n, i, up, down := len(expression), 0, 0, 1
	for i < n {
		sign, up1, down1 := 1, 0, 0
		if expression[i] == '-' || expression[i] == '+' {
			if expression[i] == '-' {
				sign = -1
			}
			i++
		}
		for i < n && unicode.IsDigit(rune(expression[i])) {
			up1 = up1*10 + int(expression[i]-'0')
			i++
		}
		i++
		up1 = sign * up1

		for i < n && unicode.IsDigit(rune(expression[i])) {
			down1 = down1*10 + int(expression[i]-'0')
			i++
		}
		up = up1*down + up*down1
		down *= down1
	}
	if up == 0 {
		return "0/1"
	}
	g := gcd(abs(up), down)
	return fmt.Sprintf("%d/%d", up/g, down/g)
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func abs(i int) int {
	if i < 0 {
		return -i
	}
	return i
}
