package sbgo

func maxRotateFunction(nums []int) int {
	res, n, acc := 0, len(nums), 0
	for i := 0; i < n; i++ {
		res += i * nums[i]
		acc += nums[i]
	}
	f := res
	for i := n - 1; i >= 0; i-- {
		f += acc - n*nums[i]
		if f > res {
			res = f
		}
	}
	return res
}
