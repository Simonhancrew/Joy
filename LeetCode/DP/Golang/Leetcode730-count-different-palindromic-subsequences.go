package sbgo

func countPalindromicSubsequences(s string) int {
	n, P := len(s), int(1e9)+7
	f := make([][]int, n+1)
	for i := 0; i <= n; i++ {
		f[i] = make([]int, n+1)
		for j := 0; j <= n; j++ {
			f[i][j] = 1
			if i == j {
				f[i][j]++
			}
		}
	}
	for length := 2; length <= n; length++ {
		q := make([][]int, 4)
		for j := 1; j <= n; j++ {
			q[s[j-1]-'a'] = append(q[s[j-1]-'a'], j)
			i := j - length + 1
			if i >= 1 {
				for k := 0; k < 4; k++ {
					for len(q[k]) > 0 && q[k][0] < i {
						q[k] = q[k][1:]
					}
					if len(q[k]) > 0 {
						f[i][j]++
						l, r := q[k][0], q[k][len(q[k])-1]
						if l < r {
							f[i][j] = (f[i][j] + f[l+1][r-1]) % P
						}
					}
				}
			}
		}
	}
	return (f[1][n] - 1 + P) % P
}
