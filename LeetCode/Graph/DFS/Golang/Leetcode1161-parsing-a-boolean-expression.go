package sbgo

func parseBoolExpr(s string) bool {
	i := 0
	var dfs func() bool
	dfs = func() bool {
		if s[i] == 't' {
			i++
			return true
		}
		if s[i] == 'f' {
			i++
			return false
		}
		op := s[i]
		i += 2
		res := true
		if op == '|' {
			res = false
		}
		for s[i] != ')' {
			if s[i] == ',' {
				i++
			}
			t := dfs()
			if op == '|' {
				res = res || t
			} else {
				res = res && t
			}
		}
		i++
		if op == '!' {
			res = !res
		}
		return res
	}
	return dfs()
}
