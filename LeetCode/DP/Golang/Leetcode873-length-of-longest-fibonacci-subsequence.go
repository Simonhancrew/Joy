package sbgo

func lenLongestFibSubseq(arr []int) int {
	n, res, mp := len(arr), 0, make(map[int]int)
	for i := 0; i < n; i++ {
		mp[arr[i]] = i
	}
	f := make([][]int, n)
	for i := 0; i < n; i++ {
		f[i] = make([]int, n)
	}
	for i := 0; i < n; i++ {
		for j := 0; j < i; j++ {
			x := arr[i] - arr[j]
			f[i][j] = 2
			if k, ok := mp[x]; x < arr[j] && ok {
				f[i][j] = max(f[i][j], f[j][k]+1)
			}
			res = max(res, f[i][j])
		}
	}
	if res < 3 {
		return 0
	}
	return res
}

func max(i, j int) int {
	if i < j {
		return j
	}
	return i
}
