package sbgo

func threeEqualParts(arr []int) []int {
	acc := 0
	for _, val := range arr {
		acc += val
	}
	if acc == 0 {
		return []int{0, 2}
	}
	if acc%3 != 0 {
		return []int{-1, -1}
	}
	avg, n := acc/3, len(arr)
	s, p := []int{1, avg, avg + 1, 2 * avg, 2*avg + 1, 3 * avg}, make([]int, 6)
	for i, j, c := 0, 0, 0; i < n; i++ {
		if arr[i] == 0 {
			continue
		}
		c++
		for j < 6 && s[j] == c {
			p[j] = i
			j++
		}
	}
	last0 := n - 1 - p[5]
	dis1, dis2 := p[2]-p[1]-1, p[4]-p[3]-1
	if dis1 < last0 || dis2 < last0 {
		return []int{-1, -1}
	}
	check := func(a, b, c, d int) bool {
		for i, j := a, c; i <= b; i, j = i+1, j+1 {
			if arr[i] != arr[j] {
				return false
			}
		}
		return true
	}
	if !check(p[0], p[1], p[2], p[3]) || !check(p[2], p[3], p[4], p[5]) {
		return []int{-1, -1}
	}
	return []int{p[1] + last0, p[3] + last0 + 1}
}
