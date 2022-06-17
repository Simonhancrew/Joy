package sbgo

func duplicateZeros(arr []int) {
	n, cnt, i := len(arr), 0, 0
	for i = 0; cnt < n; i++ {
		if arr[i] != 0 {
			cnt++
		} else {
			cnt += 2
		}
	}
	i--
	j := n - 1
	if cnt == n+1 {
		arr[j] = 0
		j--
		i--
	}
	for j >= 0 {
		arr[j] = arr[i]
		j--
		if arr[i] == 0 {
			arr[j] = arr[i]
			j--
		}
		i--
	}
}
