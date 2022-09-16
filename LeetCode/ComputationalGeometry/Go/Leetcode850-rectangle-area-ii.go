package sbgo

import "sort"

func rectangleArea(rectangles [][]int) int {
    cox := []int{}
    for _,rec := range rectangles {
        cox = append(cox,rec[0])
        cox = append(cox,rec[2])
    }
    sort.Ints(cox)
    n := len(cox)
    res := 0
    for i := 1;i < n;i++ {
        res += calcu(rectangles,cox[i - 1],cox[i])
    }
    return res % int(1e9 + 7)
}

type pair struct {
    x,y int
}

func calcu(recs [][]int,a,b int) int {
    coy := []pair{}
    for _,rec := range recs {
        if rec[0] <= a && rec[2] >= b {
            coy = append(coy,pair{rec[1],rec[3]})
        }
    }
    sort.Slice(coy,func(i,j int) bool {
        return coy[i].x < coy[j].x
    })
    res,st,ed := 0,-1,-1
    for _,y := range coy {
        if y.x > ed {
            res += ed - st
            st,ed = y.x,y.y
        }else if y.y > ed {
            ed = y.y
        }
    }
    res += ed - st
    return res * (b - a)
}
