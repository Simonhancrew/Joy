package sbgo

import (
	"strconv"
	"strings"
	"unicode"
)

func solveEquation(equation string) string {
	arr := strings.Split(equation, "=")
	get := func(s string) []int {
		a, b := 0, 0
		if s[0] != '-' && s[0] != '+' {
			s = "+" + s
		}
		for i := 0; i < len(s); i++ {
			j := i + 1
			for j < len(s) && unicode.IsDigit(rune(s[j])) {
				j++
			}
			c := 1
			if i+1 <= j-1 {
				c, _ = strconv.Atoi(s[i+1 : j])
			}
			if s[i] == '-' {
				c = -c
			}
			if j < len(s) && s[j] == 'x' {
				a += c
				i = j
			} else {
				b += c
				i = j - 1
			}
		}
		return []int{a, b}
	}
	lhs, rhs := get(arr[0]), get(arr[1])
	a, b := lhs[0]-rhs[0], rhs[1]-lhs[1]
	if a == 0 {
		if b == 0 {
			return "Infinite solutions"
		} else {
			return "No solution"
		}
	}
	return "x=" + strconv.Itoa(b/a)
}
