package sbgo

func checkOnesSegment(s string) bool {
	flag, cnt := false, 0
	for _, ch := range s {
		if ch == '1' {
			if flag {
				continue
			} else {
				cnt += 1
				if cnt > 1 {
					return false
				}
				flag = true
			}

		} else {
			flag = false
		}
	}
	return true
}
