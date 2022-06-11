package sbgo

func minFlipsMonoIncr(s string) int {
	f0, f1 := 0, 0
	for _, c := range s {
		ff0, ff1 := f0, min(f0, f1)
		if c == '1' {
			ff0++
		}
		if c == '0' {
			ff1++
		}
		f1, f0 = ff1, ff0
	}
	return min(f1, f0)
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}
