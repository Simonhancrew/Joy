package sbgo

func convertToBase7(num int) string {
	if num == 0 {
		return "0"
	}
	ans, flag := []byte{}, false
	if num < 0 {
		flag = true
		num = -num
	}
	for num > 0 {
		ans = append(ans, '0'+byte(num%7))
		num /= 7
	}
	if flag {
		ans = append(ans, '-')
	}
	for i, j := 0, len(ans)-1; i < j; i, j = i+1, j-1 {
		ans[i], ans[j] = ans[j], ans[i]
	}
	return string(ans)
}
