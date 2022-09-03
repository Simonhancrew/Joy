package sbgo

import "sort"

func findLongestChain(pairs [][]int) int {
    sort.Slice(pairs,func(i,j int) bool {
        return pairs[i][0] < pairs[j][0]
    })
    max := func(i,j int) int {
        if i < j {
            return j
        }
        return i
    }
    n, ans := len(pairs),1
    f := make([]int,n)
    for i,_ := range f {
        f[i] = 1
    }
    for i := 1;i < n;i++ {
        for j := 0;j < i;j++ {
            if pairs[i][0] > pairs[j][1] {
                f[i] = max(f[i],f[j] + 1)
            }
        }
        ans = max(ans,f[i])
    }
    return ans
}
