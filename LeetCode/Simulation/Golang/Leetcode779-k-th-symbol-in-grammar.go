package sbgo

func kthGrammar(n int, k int) int {
	if n == 1 {
		return 0
	}
	if k > (1 << (n - 2)) {
		return 1 ^ kthGrammar(n, k-(1<<(n-2)))
	}
	return kthGrammar(n-1, k)
}
