package sbgo

func corpFlightBookings(bookings [][]int, n int) []int {
	ans := make([]int, n)
	for _, bk := range bookings {
		l, r, w := bk[0], bk[1], bk[2]
		ans[l-1] += w
		if r < n {
			ans[r] -= w
		}
	}
	for i := 1; i < n; i++ {
		ans[i] += ans[i-1]
	}
	return ans
}
