package sbgo

import "math"

func kthSmallestPrimeFraction(arr []int, k int) []int {
	l, r := 0.0, 1.0
	eps := 1e-8
	a, b := 0, 0
	get := func(mid float64) int {
		res := 0
		for i, j := 0, 0; i < len(arr); i++ {
			for j+1 < len(arr) && float64(arr[j+1])/float64(arr[i]) <= mid {
				j++
			}
			if float64(arr[j])/float64(arr[i]) <= mid {
				res += j + 1
			}
			if math.Abs(float64(arr[j])/float64(arr[i])-mid) <= eps {
				a, b = arr[j], arr[i]
			}
		}
		return res
	}
	for r-l > eps {
		mid := (l + r) / 2.0
		if get(mid) >= k {
			r = mid
		} else {
			l = mid
		}
	}

	return []int{a, b}
}
