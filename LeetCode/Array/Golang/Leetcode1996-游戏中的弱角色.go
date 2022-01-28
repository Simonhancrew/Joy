package sbgo

import "sort"

func numberOfWeakCharacters(ps [][]int) int {
    sort.Slice(ps,func(l, r int) bool {
        p,q := ps[l],ps[r]
        return p[0] > q[0] || (p[0] == q[0] && p[1] < q[1]) 
    })
    ans,mx := 0,0
    for _,p := range ps{
        se := p[1]
        if se < mx {
            ans++
        }else if se > mx{
            mx = se
        }
    }
    return ans
}