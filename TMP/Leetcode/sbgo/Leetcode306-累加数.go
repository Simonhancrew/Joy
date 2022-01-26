package sbgo

func isAdditiveNumber(s string) bool {
	n, rec := len(s), [][]byte{}
	var dfs func(u int) bool
	check := func(l, r, res []byte) bool {
		carry := byte(0)
		tmp := []byte{}
		for i := 0; i < len(r) || i < len(l); i++ {
			if i < len(l) {
				carry += l[i]
			}
			if i < len(r) {
				carry += r[i]
			}
			tmp = append(tmp, carry%10)
			carry /= 10
		}
		if carry != 0 {
			tmp = append(tmp, carry)
		}
		if len(tmp) != len(res) {
			return false
		}
		for i := 0; i < len(tmp); i++ {
			if tmp[i] != res[i] {
				return false
			}
		}
		return true
	}
	dfs = func(u int) bool {
		cnt := len(rec)
		if n == u {
			return cnt >= 3
		}
		rhs := u + 1
		if s[u] != '0' {
			rhs = n
		}
		cur := []byte{}
		for i := u; i < rhs; i++ {
			cur = append([]byte{s[i] - '0'}, cur...)
			if cnt < 2 || check(rec[cnt-2], rec[cnt-1], cur) {
				rec = append(rec, cur)
				if dfs(i + 1) {
					return true
				}
				rec = rec[:len(rec)-1]
			}
		}
		return false
	}
	return dfs(0)
}
