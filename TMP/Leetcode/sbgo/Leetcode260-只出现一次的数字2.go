package sbgo

func singleNumber(nums []int) []int {
	mask, diff := 0, 1
	for _, num := range nums {
		mask ^= num
	}
	for (diff & mask) == 0 {
		diff <<= 1
	}
	a, b := 0, 0
	for _, num := range nums {
		if (diff & num) != 0 {
			a ^= num
		} else {
			b ^= num
		}
	}
	return []int{a, b}
}
