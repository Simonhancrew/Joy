package sbgo

import "strconv"

func compareVersion(v1 string, v2 string) int {
	for i, j := 0, 0; i < len(v1) || j < len(v2); {
		a, b := i, j
		for a < len(v1) && v1[a] != '.' {
			a++
		}
		for b < len(v2) && v2[b] != '.' {
			b++
		}
		x, y := 0, 0
		if a == i {
			x = 0
		} else {
			x, _ = strconv.Atoi(v1[i:a])
		}
		if b == j {
			y = 0
		} else {
			y, _ = strconv.Atoi(v2[j:b])
		}
		if x < y {
			return -1
		}
		if x > y {
			return 1
		}
		i, j = a+1, b+1
	}
	return 0
}
