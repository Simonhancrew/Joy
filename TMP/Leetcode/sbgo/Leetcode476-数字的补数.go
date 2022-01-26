package sbgo

func findComplement(num int) int {
	cnt := 0
	for x := num; x != 0; x >>= 1 {
		cnt++
	}
	// 取反在go里是^
	return ^num & ((1 << cnt) - 1)
}
