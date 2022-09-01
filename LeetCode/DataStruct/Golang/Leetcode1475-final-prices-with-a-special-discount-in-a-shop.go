package sbgo

func finalPrices(prices []int) []int {
    ans,n := []int{},len(prices)
    for i := n - 1;i >= 0;i-- {
        for len(ans) != 0 && ans[len(ans) - 1] > prices[i] {
            ans = ans[:len(ans) - 1]
        }
        t := prices[i]
        if len(ans) != 0 {
            prices[i] -= ans[len(ans) - 1]
        }
        ans = append(ans,t)
    }
    return prices
}
