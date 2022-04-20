package sbgo

import "strings"

func lengthLongestPath(input string) int {
	res, stk := 0, []int{}
	for i, sum := 0, 0; i < len(input); i++ {
		k := 0
		for i < len(input) && input[i] == '\t' {
			i++
			k++
		}
		for k < len(stk) {
			sum -= stk[len(stk)-1]
			stk = stk[:len(stk)-1]
		}
		j := i
		for j < len(input) && input[j] != '\n' {
			j++
		}
		length := j - i
		stk = append(stk, length)
		sum += length
		if strings.Contains(input[i:j-1], ".") {
			res = max(res, sum+len(stk)-1)
		}
		i = j
	}
	return res
}

func max(i, j int) int {
	if i < j {
		return j
	}
	return i
}
