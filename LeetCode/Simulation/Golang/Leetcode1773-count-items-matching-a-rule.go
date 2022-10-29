package sbgo

func countMatches(items [][]string, ruleKey string, ruleValue string) int {
	n, ans, key := len(items), 0, 0
	if ruleKey == "color" {
		key = 1
	} else if ruleKey == "name" {
		key = 2
	}
	for i := 0; i < n; i++ {
		if items[i][key] == ruleValue {
			ans++
		}
	}
	return ans
}
