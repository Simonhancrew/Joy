package sbgo

func toGoatLatin(s string) string {
	st, ins := map[byte]bool{}, "aeiouAEIOU"
	for _, t := range ins {
		st[byte(t)] = true
	}
	res, n, cur := "", len(s), "a"
	for i := 0; i < n; i++ {
		if i != 0 {
			res += " "
		}
		j := i
		for j < n && s[j] != ' ' {
			j++
		}
		tmp := s[i:j]
		if st[tmp[0]] {
			res += tmp + "ma"
		} else {
			res += tmp[1:] + string(tmp[0]) + "ma"
		}
		res += cur
		cur += "a"
		i = j
	}
	return res
}
