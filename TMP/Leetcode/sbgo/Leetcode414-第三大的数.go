package sbgo

// golang的int是根据os变的，64位os就是64位
// 所以在做的时候可能没有影响，但是还是应该设成int64

func thirdMax(nums []int) int {
	INF := (int)(-1e10)
	cnt, f1, f2, f3 := 0, INF, INF, INF
	for _, x := range nums {
		if x > f3 {
			cnt++
			f1, f2, f3 = f2, f3, x
		} else if x < f3 && x > f2 {
			cnt++
			f1, f2 = f2, x
		} else if x < f2 && x > f1 {
			cnt++
			f1 = x
		}
	}
	if cnt < 3 {
		return f3
	}
	return f1
}
