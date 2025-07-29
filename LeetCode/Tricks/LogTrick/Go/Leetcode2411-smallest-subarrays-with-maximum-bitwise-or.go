func smallestSubarrays(nums []int) []int {
    ans := make([]int, len(nums))
    for i := 0;i < len(nums);i++ {
        ans[i] = 1;
        for j := i - 1;j >= 0 && nums[j] | nums[i] != nums[j];j-- {
            ans[j] = i - j + 1;
            nums[j] |= nums[i];
        }
    }
    return ans
}
