package sbgo

import "strconv"

func diffWaysToCompute(expression string) []int {
	res, n := []int{}, len(expression)
	for i := 0; i < n; i++ {
		if expression[i] == '+' || expression[i] == '-' || expression[i] == '*' {
			left := diffWaysToCompute(expression[:i])
			right := diffWaysToCompute(expression[i+1:])
			for _, lhs := range left {
				for _, rhs := range right {
					if expression[i] == '+' {
						res = append(res, lhs+rhs)
					} else if expression[i] == '-' {
						res = append(res, lhs-rhs)
					} else {
						res = append(res, lhs*rhs)
					}
				}
			}
		}
	}
	if len(res) == 0 {
		t, _ := strconv.Atoi(expression)
		res = append(res, t)
	}
	return res
}
