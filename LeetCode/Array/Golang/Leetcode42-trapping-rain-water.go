package sbgo

func trap(height []int) int {
    n := len(height)
    max := func(i, j int) int {
        if i < j {
            return j
        }
        return i
    }
    min := func(i, j int) int {
        if i > j {
            return j
        }
        return i
    }
    l, r := make([]int, n), make([]int, n)
    l[0], r[n - 1] = height[0], height[n - 1]
    for i := 1;i < n;i++ {
        l[i] = max(l[i - 1], height[i])
    }
    for i := n - 2;i > 0;i-- {
        r[i] = max(r[i + 1], height[i])
    }
    ans := 0
    for i := 1;i < n - 1;i++ {
        ans += min(l[i], r[i]) - height[i]
    }
    return ans
}
