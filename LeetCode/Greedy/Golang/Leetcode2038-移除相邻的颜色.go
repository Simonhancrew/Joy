package sbgo

func winnerOfGame(colors string) bool {
	cnt, f, cur := 1, []int{0, 0}, byte('C')
	for i := 0; i < len(colors); i++ {
		if cur != colors[i] {
			cur = colors[i]
			cnt = 1
		} else {
			cnt++
			if cnt >= 3 {
				f[cur-'A']++
			}
		}
	}
	return f[0] > f[1]
}
