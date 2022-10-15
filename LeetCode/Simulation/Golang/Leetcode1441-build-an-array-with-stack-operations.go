package sbgo

func buildArray(target []int, n int) []string {
	ans := []string{}
	for i, j := 1, 0; i <= n; i++ {
		if target[j] == i {
			j++
			ans = append(ans, "Push")
		} else {
			ans = append(ans, "Push")
			ans = append(ans, "Pop")
		}
		if i == target[len(target)-1] {
			break
		}
	}
	return ans
}
