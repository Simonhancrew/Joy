package sbgo

func constructRectangle(area int) []int {
	l, w := 0, 0
	for i := 1; i <= area/i; i++ {
		if area%i != 0 {
			continue
		}
		j := area / i
		if l*w == 0 || l-w > j-i {
			l, w = j, i
		}
	}
	return []int{l, w}
}
