package sbgo

func minOperations(logs []string) int {
	stp, n := 0, len(logs)
	for i := 0; i < n; i++ {
		if logs[i] == "./" || (logs[i] == "../" && stp == 0) {
			continue
		}
		if logs[i] == "../" {
			stp--
		} else {
			stp++
		}
	}
	return stp
}
