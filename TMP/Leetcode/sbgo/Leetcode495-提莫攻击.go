package sbgo

func findPoisonedDuration(timeSeries []int, duration int) int {
	ans, last := 0, -1
	for _, x := range timeSeries {
		t := x + duration - 1
		if x > last {
			ans += duration
		} else {
			ans += t - last
		}
		last = t
	}
	return ans
}
