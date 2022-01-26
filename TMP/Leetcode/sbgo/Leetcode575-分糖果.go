package sbgo

func distributeCandies(candyType []int) int {
	mp := map[int]int{}
	for _, val := range candyType {
		mp[val]++
	}
	return min(len(mp), len(candyType)/2)
}
