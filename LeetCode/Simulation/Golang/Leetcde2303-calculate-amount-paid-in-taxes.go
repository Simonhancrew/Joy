package sbgo

func calculateTax(brackets [][]int, income int) float64 {
	pre := 0
	ans := 0.0
	for _, x := range brackets {
		if income >= x[0] {
			ans += float64((x[0]-pre)*x[1]) / 100.0
			pre = x[0]
		} else {
			ans += float64((income-pre)*x[1]) / 100.0
			break
		}
	}
	return ans
}
