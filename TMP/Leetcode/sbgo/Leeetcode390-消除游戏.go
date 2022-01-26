package sbgo

func lastRemaining(n int) int {
	if n == 1 {
		return 1
	}
	return 2 * (n/2 + 1 - lastRemaining(n/2))
}
