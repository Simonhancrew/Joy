package sbgo

func missingRolls(rolls []int, mean int, n int) []int {
	m, suma := len(rolls), 0
	for i := 0; i < m; i++ {
		suma += rolls[i]
	}
	sumb := (n+m)*mean - suma
	ev, lf := sumb/n, sumb%n
	if ev < 1 || ev > 6 {
		return []int{}
	}
	if ev == 6 && lf > 0 {
		return []int{}
	}
	res := make([]int, n)
	for i := 0; i < n; i++ {
		res[i] = ev
		if lf != 0 {
			res[i]++
			lf--
		}
	}
	return res
}
