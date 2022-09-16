package sbgo

func maxLengthBetweenEqualCharacters(s string) int {
    rec := make([]int,26)
    for i := 0;i < 26;i++ {
        rec[i] = -1
    }
    max := func(i,j int) int {
        if i < j {
            return j
        }
        return i
    }
    ans,n := -1,len(s)
    for i := 0;i < n;i++ {
        if rec[s[i] - 'a'] < 0 {
            rec[s[i] - 'a'] = i
        } else {
            ans = max(ans, i - rec[s[i] - 'a'] - 1)
        }
    }
    return ans
}
