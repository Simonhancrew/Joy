package sbgo

func findLUSlength(a string, b string) int {
	if a == b {
		return -1
	}
	return max(len(a), len(b))
}
func max(i, j int) int {
	if i < j {
		return j
	}
	return i
}
