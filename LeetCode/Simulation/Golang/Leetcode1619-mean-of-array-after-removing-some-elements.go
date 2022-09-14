package sbgo

func trimMean(arr []int) float64 {
    n,acc := len(arr),0
    sort.Ints(arr)
    for i := n / 20;i < (19 * n) / 20;i++ {
        acc += arr[i]
    }
    return float64(acc) / (0.9 * float64(n))
}
