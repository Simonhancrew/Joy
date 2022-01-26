package sbgo

import "strconv"

func dayOfYear(date string) int {
	nums := []int{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	y, _ := strconv.Atoi(date[:4])
	m, _ := strconv.Atoi(date[5:7])
	d, _ := strconv.Atoi(date[8:])
	is_leap := false
	if y%400 == 0 || (y%4 == 0 && y%100 != 0) {
		is_leap = true
	}
	ans := 0
	for i := 0; i < m-1; i++ {
		ans += nums[i]
		if is_leap && i == 1 {
			ans += 1
		}
	}
	return ans + d
}
