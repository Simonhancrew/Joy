package sbgo

func validUtf8(data []int) bool {
	n := len(data)
	get := func(a, b int) int {
		return (a >> b) & 1
	}
	for i := 0; i < n; i++ {
		if get(data[i], 7) == 0 {
			continue
		}
		cnt := 0
		for cnt <= 4 && get(data[i], 7-cnt) == 1 {
			cnt++
		}
		if cnt == 1 || cnt > 4 {
			return false
		}
		for j := 1; j < cnt; j++ {
			t := i + j
			if t >= n {
				return false
			}
			if !(get(data[t], 7) == 1 && get(data[t], 6) == 0) {
				return false
			}
		}
		i += cnt - 1
	}
	return true
}
