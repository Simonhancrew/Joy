package sbgo

type void struct{}

var member void

func removeInvalidParentheses(s string) []string {
	st := map[string]struct{}{}
	l, r := 0, 0
	for _, ch := range s {
		if ch == '(' {
			l++
		} else if ch == ')' {
			if l > 0 {
				l--
			} else {
				r++
			}
		}
	}
	var dfs func(string, string, int, int, int, int)
	dfs = func(s, cur string, idx, cnt, l, r int) {
		if l+r > len(s)-idx { // 剪枝
			return
		}
		if idx == len(s) {
			if cnt == 0 {
				st[cur] = member
			}
			return
		}
		if s[idx] == '(' {
			dfs(s, cur+"(", idx+1, cnt+1, l, r)
			if l > 0 {
				dfs(s, cur, idx+1, cnt, l-1, r)
			}
		} else if s[idx] == ')' {
			if cnt > 0 {
				dfs(s, cur+")", idx+1, cnt-1, l, r)
			}
			if r > 0 {
				dfs(s, cur, idx+1, cnt, l, r-1)
			}
		} else {
			dfs(s, cur+string(s[idx]), idx+1, cnt, l, r)
		}
	}
	var cur string
	dfs(s, cur, 0, 0, l, r)
	ans := make([]string, 0)
	for k, _ := range st {
		ans = append(ans, k)
	}
	return ans
}
