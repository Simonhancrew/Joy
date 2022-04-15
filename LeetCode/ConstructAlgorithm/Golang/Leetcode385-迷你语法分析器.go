package sbgo

import "strconv"

func deserialize(s string) *NestedInteger {
	var dfs func(string) NestedInteger
	u := 0
	dfs = func(s string) NestedInteger {
		res := NestedInteger{}
		if s[u] == '[' {
			u++
			for s[u] != ']' {
				res.Add(dfs(s))
			}
			u++
			if u < len(s) && s[u] == ',' {
				u++
			}
		} else {
			k := u
			for k < len(s) && s[k] != ',' && s[k] != ']' {
				k++
			}
			t, _ := strconv.Atoi(s[u:k])
			res.SetInteger(t)
			if k < len(s) && s[k] == ',' {
				k++
			}
			u = k
		}
		return res
	}
	res := dfs(s)
	return &res
}
