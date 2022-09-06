package sbgo

func uniqueLetterString(s string) int {
    n := len(s)
    l,r,last := make([]int,n),make([]int,n),make([]int,26)
    for i := 0;i < 26;i++ {
        last[i] = -1;
    }
    for i := 0;i < n;i++ {
        l[i] = last[s[i] - 'A']
        last[s[i] - 'A'] = i
    }
    for i := 0;i < 26;i++ {
        last[i] = n
    }
    for i := n - 1;i >= 0;i-- {
        r[i] = last[s[i] - 'A']
        last[s[i] - 'A'] = i
    }
    ans := 0
    for i := 0;i < n;i++ {
        ans += (i - l[i]) * (r[i] - i)
    }
    return ans
}
