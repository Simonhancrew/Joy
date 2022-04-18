package sbgo

func lexicalOrder(n int) []int {
	var dfs func(int, int)
	res := []int{}
	dfs = func(cur, n int) {
		if cur <= n {
			res = append(res, cur)
		} else {
			return
		}
		for i := 0; i <= 9; i++ {
			dfs(cur*10+i, n)
		}
	}
	for i := 1; i <= 9; i++ {
		dfs(i, n)
	}
	return res
}
