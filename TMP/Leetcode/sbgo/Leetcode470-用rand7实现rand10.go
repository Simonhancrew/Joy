package sbgo

// 拒绝采样

func rand10() int {
	for true {
		t := (rand7()-1)*7 + rand7()
		if t <= 40 {
			return t%10 + 1
		}
	}
	return -1
}
