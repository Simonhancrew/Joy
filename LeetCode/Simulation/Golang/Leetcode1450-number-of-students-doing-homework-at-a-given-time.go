package sbgo

func busyStudent(startTime []int, endTime []int, queryTime int) int {
	ans, n := 0, len(startTime)
	for i := 0; i < n; i++ {
		if startTime[i] <= queryTime && queryTime <= endTime[i] {
			ans++
		}
	}
	return ans
}
