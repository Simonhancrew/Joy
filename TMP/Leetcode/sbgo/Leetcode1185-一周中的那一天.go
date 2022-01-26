package sbgo

func dayOfTheWeek(day int, month int, year int) string {
	ans := []string{"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"}
	cnt := []int{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30}
	days := 0
	for i := 1971; i < year; i++ {
		days += 365
		if i%400 == 0 || (i%4 == 0 && i%100 != 0) {
			days += 1
		}
	}
	for i := 0; i < month-1; i++ {
		days += cnt[i]
	}
	if month > 2 && (year%400 == 0 || (year%4 == 0 && year%100 != 0)) {
		days += 1
	}
	days += day
	return ans[(days+3)%7]
}
