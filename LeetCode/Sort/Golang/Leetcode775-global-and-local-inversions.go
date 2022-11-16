package sbgo

func isIdealPermutation(nums []int) bool {
    lmin, n := nums[len(nums) - 1], len(nums)
    min := func(i, j int) int {
        if i < j {
            return i
        }
        return j
    }
    for i := n - 2;i > 0;i-- {
        if nums[i - 1] > lmin {
            return false;
        }
        lmin = min(lmin, nums[i])
    }
    return true
}
