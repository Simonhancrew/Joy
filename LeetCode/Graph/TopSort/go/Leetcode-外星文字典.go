package sbgo

import "strings"

func alienOrder(words []string) string {
	mp, din := make(map[byte][]byte), make(map[byte]int)
	n := len(words)
	for _, word := range words {
		for i := 0; i < len(word); i++ {
			c := word[i]
			if _, ok := mp[c]; !ok {
				mp[c] = []byte{}
			}
		}
	}
	flag := true

	build := func(l, r string) {
		i, n := 0, min(len(l), len(r))
		for i < n {
			a, b := l[i], r[i]
			if a != b {
				mp[a] = append(mp[a], b)
				din[b]++
				break
			}
			i++
		}
		if i == n && len(l) > len(r) {
			flag = false
		}
	}

	for i := 1; i < n && flag; i++ {
		build(words[i-1], words[i])
	}
	if !flag {
		return ""
	}

	res := strings.Builder{}

	topsort := func() bool {
		q := []byte{}
		for k := range mp {
			if _, ok := din[k]; !ok {
				q = append(q, k)
			}
		}

		for len(q) != 0 {
			t := q[0]
			q = q[1:]
			res.WriteByte(t)
			for _, ne := range mp[t] {
				din[ne]--
				if din[ne] == 0 {
					q = append(q, ne)
				}
			}
		}
		if res.Len() != len(mp) {
			return false
		}
		return true
	}

	if !topsort() {
		return ""
	}

	return res.String()
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}
