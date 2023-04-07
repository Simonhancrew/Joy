package sbgo


func numMovesStonesII(stones []int) []int {
    n := len(stones)
    sort.Ints(stones)
    min := func(i, j int) int {
        if i < j {
            return i
        }
        return j
    }
    tot := stones[n - 1] - stones[0] + 1 - n;
    res := []int{n, 0}
    res[1] = tot - min(stones[1] - stones[0] - 1, stones[n - 1] - stones[n - 2] - 1)
    for i, j := 0, 0;i < n;i++ {
        // 尽可能多的放点
        for stones[i] - stones[j] + 1 > n {
            j++
        }
        m := i - j + 1
        // n - 1的时候特判一下， 别的都是n - m
        if m == n - 1 && stones[i] - stones[j] == i - j {
            res[0] = min(res[0], 2)
        } else {
            res[0] = min(res[0], n - m)
        }
    }
    return res
}
