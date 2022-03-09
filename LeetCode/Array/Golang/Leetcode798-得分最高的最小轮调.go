package sbgo

func bestRotation(nums []int) int {
	n := len(nums)
	b := make([]int, n+1)
	for i := 0; i < n; i++ {
		l, r := i-nums[i]+1, i
		if l >= 0 {
			b[l]++
			b[r+1]--
		} else {
			b[0], b[r+1] = b[0]+1, b[r+1]-1
			b[l+n], b[n] = b[l+n]+1, b[n]-1
		}
	}
	res, k := int(1e6), -1
	for i, sum := 0, 0; i < n; i++ {
		sum += b[i]
		if res > sum {
			res = sum
			k = i
		}
	}
	return k
}
