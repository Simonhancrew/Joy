package sbgo

func maximumWealth(accounts [][]int) int {
	mx := 0
	for _, x := range accounts {
		cur := 0
		for _, t := range x {
			cur += t
		}
		if cur > mx {
			mx = cur
		}
	}
	return mx
}
