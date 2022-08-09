func minStartValue(nums []int) int {
    ans,acc := 1,0
    for _,num := range nums {
        acc += num
        nag := 1 - acc 
        if ans < nag {
            ans = nag
        }
    }
    return ans
}
