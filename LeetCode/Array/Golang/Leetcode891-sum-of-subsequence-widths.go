package sbgo



func sumSubseqWidths(nums []int) int {
    n, P := len(nums), int(1e9 + 7)
    p := make([]int, n + 1)
    p[0] = 1
    for i := 1;i <= n;i++ {
        p[i] = p[i - 1] * 2 % P
    }
    sort.Ints(nums)
    res := 0
    for i := 0;i < n;i++ {
        res = (res + nums[i] * p[i] - nums[i] * p[n - i - 1]) % P
    }
    return res
}
