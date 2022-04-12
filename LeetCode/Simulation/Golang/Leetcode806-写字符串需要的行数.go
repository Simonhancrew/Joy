package sbgo

func numberOfLines(widths []int, s string) []int {
	cnt, line := 0, 1
	for _, x := range s {
		t := widths[x-'a']
		cnt += t
		if cnt > 100 {
			cnt = t
			line++
		}
	}
	return []int{line, cnt}
}
