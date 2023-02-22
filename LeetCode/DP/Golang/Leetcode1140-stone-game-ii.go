package sbgo

func stoneGameII(piles []int) int {
    n := len(piles)
    s := make([]int, n + 1)
    f := make([][]int, n + 2)
    for i := 0;i < n + 2;i++ {
        f[i] = make([]int, n + 1)
    }
    for i := 1;i <= n;i++ {
        s[i] = s[i - 1] + piles[i - 1]
    }
    max := func(i, j int) int {
        if i < j {
            return j
        }
        return i
    }
    for i := n;i > 0;i-- {
        for j := 1;j <= n;j++ {
            for k := 1;i + k - 1 <= n && k <= 2 * j;k++ {
                f[i][j] = max(f[i][j], s[n] - s[i - 1] - f[i + k][max(k, j)])
            }
        }
    }
    return f[1][1]
}

