func threeSumClosest(nums []int, target int) int {
	res := []float64{1e9, 1e9}
	n := len(nums)
	sort.Ints(nums)
	for i := 0;i < n  - 2;i++ {
			for j, k := i + 1, n - 1;j < k;j++ {
					for j < k - 1 && nums[i] + nums[j] + nums[k] > target {
							k--
					}
					sum := float64(nums[i] + nums[j] + nums[k])
					if math.Abs(sum - float64(target)) < res[0] {
							res = []float64{math.Abs(sum - float64(target)), sum}
					}
					if j < k - 1 {
							sum = float64(nums[i] + nums[j] + nums[k - 1])
							if math.Abs(sum - float64(target)) < res[0] {
									res = []float64{math.Abs(sum - float64(target)), sum}
							}
					}
			}   
	}
	return int(res[1])
}