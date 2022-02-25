package sbgo

import (
	"fmt"
	"strconv"
	"strings"
)

func complexNumberMultiply(num1 string, num2 string) string {
	r1, i1 := parse(num1)
	r2, i2 := parse(num2)
	return fmt.Sprintf("%d+%di", r1*r2-i1*i2, r1*i2+r2*i1)
}

func parse(s string) (int, int) {
	idx := strings.IndexByte(s, '+')
	r, _ := strconv.Atoi(s[:idx])
	i, _ := strconv.Atoi(s[idx+1 : len(s)-1])
	return r, i
}
