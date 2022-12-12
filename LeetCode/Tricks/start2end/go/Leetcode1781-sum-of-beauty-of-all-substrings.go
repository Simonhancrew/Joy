package sbgo

func beautySum(s string) int {
    res, n := 0, len(s)
    max := func(i, j int) int {
        if i < j {
            return j
        }
        return i
    }
    min := func(i, j int) int {
        if i < j {
            return i
        }
        return j
    }
    for i := 0;i < n;i++ {
        mp := make([]int, 26)
        mx := 0
        for j := i;j < n;j++ {
            mp[s[j] - 'a']++
            mx = max(mx, mp[s[j] - 'a'])
            mn := n
            for k := 0;k < 26;k++ {
                if mp[k] > 0 {
                    mn = min(mn, mp[k])
                }
            }
            res += mx - mn
        }
    }
    return res
}
