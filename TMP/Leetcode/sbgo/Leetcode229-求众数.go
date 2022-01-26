package sbgo

func majorityElement(nums []int) []int {
	c1, c2, r1, r2 := 0, 0, 0, 0
	for _, x := range nums {
		if r1 != 0 && x == c1 {
			r1++
		} else if r2 != 0 && x == c2 {
			r2++
		} else if r1 == 0 {
			r1, c1 = 1, x
		} else if r2 == 0 {
			r2, c2 = 1, x
		} else {
			r1, r2 = r1-1, r2-1
		}
	}
	r1, r2 = 0, 0
	for _, x := range nums {
		if c1 == x {
			r1++
		} else if c2 == x {
			r2++
		}
	}
	ans := []int{}
	n := len(nums)
	if r1 > n/3 {
		ans = append(ans, c1)
	}
	if r2 > n/3 {
		ans = append(ans, c2)
	}
	return ans
}
