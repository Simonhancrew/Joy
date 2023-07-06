func maximumEvenSplit(finalSum int64) []int64 {
	if finalSum & 1 != 0 {
			return []int64{}
	}
	ans := []int64{}
	for i := int64(2);finalSum >= i;i += 2 {
			ans = append(ans, i)
			finalSum -= i
	}
	if finalSum != 0 {
			n := len(ans)
			ans[n - 1] += finalSum
	}
	return ans
}