package sbgo

func minSideJumps(obstacles []int) int {
	n := len(obstacles)
	f := []int{1, 0, 1}
	min := func(i, j int) int {
		if i < j {
			return i
		}
		return j
	}
	for i := 1; i < n; i++ {
		mn := 0x3f3f3f3f
		for j := 0; j < 3; j++ {
			if obstacles[i] == j+1 {
				f[j] = 0x3f3f3f3f
				continue
			}
			mn = min(mn, f[j])
		}
		for j := 0; j < 3; j++ {
			if obstacles[i] == j+1 {
				continue
			}
			f[j] = min(f[j], mn+1)
		}
	}
	return min(f[0], min(f[1], f[2]))
}
