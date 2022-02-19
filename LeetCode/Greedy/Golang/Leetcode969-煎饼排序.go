package sbgo

func pancakeSort(arr []int) []int {
	n := len(arr)
	res := []int{}
	rev := func(end int) {
		l, r := 0, end
		for l < r {
			arr[l], arr[r] = arr[r], arr[l]
			l++
			r--
		}
	}
	for i := n - 1; i >= 0; i-- {
		mx := 0
		for j := 0; j <= i; j++ {
			if arr[j] > arr[mx] {
				mx = j
			}
		}
		if mx == i {
			continue
		}
		rev(mx)
		res = append(res, mx+1)
		rev(i)
		res = append(res, i+1)
	}
	return res
}
