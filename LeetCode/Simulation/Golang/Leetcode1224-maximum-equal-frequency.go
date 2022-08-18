package sbgo

func maxEqualFreq(nums []int) int {
	ans, n, max_f := 0, len(nums), 0
	cnt, freq := map[int]int{}, map[int]int{}
	for i := 0; i < n; i++ {
		num := nums[i]
		if cnt[num] > 0 {
			freq[cnt[num]]--
		}
		cnt[num]++
		freq[cnt[num]]++
		if cnt[num] > max_f {
			max_f = cnt[num]
		}
		if max_f == 1 || max_f*freq[max_f] == i || (max_f-1)*(freq[max_f-1]+1) == i {
			ans = i + 1
		}
	}
	return ans
}
