package sbgo

func catMouseGame(g [][]int) int {
	n := len(g)
	f := make([][][]int, n*2+3)
	for i := range f {
		f[i] = make([][]int, n)
		for j := range f[i] {
			f[i][j] = make([]int, n)
			for k := range f[i][j] {
				f[i][j][k] = -1
			}
		}
	}
	var dp func(int, int, int) int
	dp = func(k, i, j int) int {
		v := &f[k][i][j]
		if k > 2*n {
			*v = 0
			return 0
		}
		if *v != -1 {
			return *v
		}
		if i == 0 {
			*v = 1
			return 1
		}
		if i == j {
			*v = 2
			return 2
		}
		draws := 0
		if k%2 == 0 {
			for _, x := range g[i] {
				t := dp(k+1, x, j)
				if t == 1 {
					*v = 1
					return 1
				}
				if t == 0 {
					draws++
				}
			}
			if draws != 0 {
				*v = 0
				return 0
			}
			*v = 2
			return 2
		}
		for _, x := range g[j] {
			if x == 0 {
				continue
			}
			t := dp(k+1, i, x)
			if t == 2 {
				*v = 2
				return 2
			}
			if t == 0 {
				draws++
			}
		}
		if draws != 0 {
			*v = 0
			return 0
		}
		*v = 1
		return 1
	}
	return dp(0, 1, 2)
}
