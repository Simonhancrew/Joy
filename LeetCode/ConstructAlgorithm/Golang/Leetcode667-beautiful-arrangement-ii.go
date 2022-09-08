package sbgo

func constructArray(n int, k int) []int {
    ans := []int{}
    for i := 1;i < n - k;i++ {
        ans = append(ans,i)
    }
    for i,j := n - k,n;i <= j;i,j = i + 1,j - 1 {
        ans = append(ans,i)
        if i != j {
            ans = append(ans,j)
        }
    }
    return ans
}
