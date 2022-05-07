package sbgo

func minMutation(start string, end string, bank []string) int {
	st, dist, q := map[string]bool{}, map[string]int{}, []string{}
	id := [4]byte{'A', 'C', 'G', 'T'}
	for _, x := range bank {
		st[x] = true
	}
	dist[start] = 0
	q = append(q, start)
	for len(q) != 0 {
		t := q[0]
		q = q[1:]
		for i := 0; i < 8; i++ {
			s := []byte(t)
			for _, x := range id {
				s[i] = x
				ss := string(s)
				if _, ok := dist[ss]; !ok && st[ss] { // if内部变量声明语句，且必须在最前
					dist[ss] = dist[t] + 1
					if ss == end {
						return dist[ss]
					}
					q = append(q, ss)
				}
			}
		}
	}
	return -1
}
