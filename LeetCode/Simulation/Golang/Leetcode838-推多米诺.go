package sbgo

func pushDominoes(dominoes string) string {
	t := "L" + dominoes + "R"
	s, n := []byte(t), len(t)
	l, r := make([]int, n), make([]int, n)
	for i, j := 0, 0; i < n; i++ {
		if s[i] != '.' {
			j = i
		}
		l[i] = j
	}
	for i, j := n-1, 0; i >= 0; i-- {
		if s[i] != '.' {
			j = i
		}
		r[i] = j
	}
	for i := 0; i < n; i++ {
		lhs, rhs := s[l[i]], s[r[i]]
		if lhs == 'L' && rhs == 'R' {
			s[i] = '.'
		} else if lhs == 'L' && rhs == 'L' {
			s[i] = 'L'
		} else if lhs == 'R' && rhs == 'R' {
			s[i] = 'R'
		} else {
			if i-l[i] < r[i]-i {
				s[i] = 'R'
			} else if i-l[i] > r[i]-i {
				s[i] = 'L'
			} else {
				s[i] = '.'
			}
		}
	}
	return string(s[1 : n-1])
}
