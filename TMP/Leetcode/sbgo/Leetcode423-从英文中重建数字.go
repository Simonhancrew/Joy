package sbgo

import "sort"

func originalDigits(s string) string {
	name := []string{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}
	ord := []int{0, 8, 3, 2, 6, 4, 5, 1, 7, 9}
	mp := map[rune]int{}
	for _, ch := range s {
		mp[ch]++
	}
	res := []byte{}
	for _, x := range ord {
		flag := true
		for flag {
			for _, ch := range name[x] {
				if ok := mp[ch]; ok == 0 {
					flag = false
					break
				}
			}
			if flag {
				res = append(res, byte('0')+byte(x))
				for _, ch := range name[x] {
					mp[ch]--
				}
			}
		}
	}
	sort.Slice(res, func(i, j int) bool {
		return res[i] < res[j]
	})
	return string(res)
}
