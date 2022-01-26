package sbgo

import "strconv"

func fractionToDecimal(numerator int, denominator int) string {
	if numerator%denominator == 0 {
		return strconv.Itoa(numerator / denominator)
	}
	var ans string
	if (numerator < 0) != (denominator < 0) {
		ans = "-"
	}
	up, down := abs(numerator), abs(denominator)
	// 整数
	ans += strconv.Itoa(up/down) + "."
	// 小数部分
	st := map[int]int{}
	up = up % down * 10
	for up != 0 {
		if _, ok := st[up]; ok {
			ans = ans[:st[up]] + "(" + ans[st[up]:]
			ans += ")"
			break
		}
		st[up] = len(ans)
		ans += strconv.Itoa(up / down)
		up = up % down * 10
	}
	return ans
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
