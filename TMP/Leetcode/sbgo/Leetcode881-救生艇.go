package sbgo

import "sort"

func numRescueBoats(people []int, limit int) int {
	sort.Ints(people)
	res := 0
	for i, j := 0, len(people)-1; i <= j; j-- {
		if people[i]+people[j] <= limit {
			i++
		}
		res++
	}
	return res
}
