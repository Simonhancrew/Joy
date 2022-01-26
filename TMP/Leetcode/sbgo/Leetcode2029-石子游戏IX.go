package sbgo

func stoneGameIX(stones []int) bool {
	cnt := make([]int, 3)
	for _, st := range stones {
		cnt[st%3]++
	}
	if cnt[0]%2 == 0 {
		return cnt[1] >= 1 && cnt[2] >= 1
	}
	return cnt[1]-cnt[2] > 2 || cnt[2]-cnt[1] > 2
}
