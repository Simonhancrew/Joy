package sbgo

func findClosestElements(arr []int, k int, x int) []int {
	l, r := 0, len(arr)-1
	for l < r {
		mid := (l + r) >> 1
		if arr[mid] > x {
			r--
		} else {
			l++
		}
	}
	l = r - 1
	for i := 0; i < k; i++ {
		if l < 0 {
			r++
		} else if r >= len(arr) || x-arr[l] <= arr[r]-x {
			l--
		} else {
			r++
		}
	}
	ans := []int{}
	for i := l + 1; i < r; i++ {
		ans = append(ans, arr[i])
	}
	return ans
}
