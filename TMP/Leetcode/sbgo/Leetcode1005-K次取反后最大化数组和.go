package sbgo

func largestSumAfterKNegations(nums []int, k int) int {
	cnt := map[int]int{}
	mn := int(1e9)
	for _, num := range nums {
		cnt[num]++
		mn = min(mn, abs(num))
	}

	for i := -100; i < 0 && k > 0; i++ {
		for _, ok := cnt[i]; ok && k > 0 && cnt[i] > 0; k-- {
			cnt[i]--
			cnt[-i]++
		}
	}
	res := 0
	for i := -100; i <= 100; i++ {
		if t, ok := cnt[i]; ok {
			res += t * i
		}
	}
	if k&1 == 1 {
		res -= 2 * mn
	}
	return res
}
