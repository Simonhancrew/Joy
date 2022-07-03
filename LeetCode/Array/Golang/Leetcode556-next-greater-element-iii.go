package sbgo

import "strconv"

func nextGreaterElement(n int) int {
	t := strconv.Itoa(n)
	s := []byte(t)
	i := len(s) - 1
	for i != 0 && s[i-1] >= s[i] {
		i--
	}
	if i == 0 {
		return -1
	}
	j := i
	for j+1 < len(s) && s[j+1] > s[i-1] {
		j++
	}
	s[j], s[i-1] = s[i-1], s[j]
	j = len(s) - 1
	for i < j {
		s[i], s[j] = s[j], s[i]
		i++
		j--
	}
	ans, _ := strconv.Atoi(string(s))
	if ans > (1<<31)-1 {
		return -1
	}
	return ans
}
