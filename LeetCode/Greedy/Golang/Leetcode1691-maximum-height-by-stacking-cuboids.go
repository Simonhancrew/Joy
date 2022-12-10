package sbgo

import (
	"fmt"
	"sort"
)

func maxHeight(cuboids [][]int) int {
	for _, x := range cuboids {
		sort.Ints(x)
	}
	sort.Slice(cuboids, func(i, j int) bool {
		if cuboids[i][0] != cuboids[j][0] {
			return cuboids[i][0] > cuboids[j][0]
		}
		if cuboids[i][1] != cuboids[j][1] {
			return cuboids[i][1] > cuboids[j][1]
		}
		return cuboids[i][2] >= cuboids[j][2]
	})
	fmt.Println(cuboids)
	n, res := len(cuboids), 0
	max := func(i, j int) int {
		if i < j {
			return j
		}
		return i
	}
	f := make([]int, n)
	for i := 0; i < n; i++ {
		f[i] = cuboids[i][2]
		for j := 0; j < i; j++ {
			if cuboids[j][1] >= cuboids[i][1] && cuboids[j][2] >= cuboids[i][2] {
				f[i] = max(f[i], f[j]+cuboids[i][2])
			}
		}
		res = max(f[i], res)
	}
	return res
}
