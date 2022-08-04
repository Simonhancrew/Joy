package sbgo

import "sort"

func minSubsequence(nums []int) []int {
    ans,acc,sum,n := []int{},0,0,len(nums)
    for _,item := range nums {
        sum += item
    }
    sort.Ints(nums)
    for i := n - 1;i >= 0 && acc <= sum;i-- {
        ans = append(ans,nums[i])
        acc += nums[i]
        sum -= nums[i]
    } 
    return ans
}
