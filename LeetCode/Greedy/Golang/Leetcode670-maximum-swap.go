package sbgo

func maximumSwap(num int) int {
    rec := []int{}
    for num != 0 {
        rec = append(rec,num % 10)
        num /= 10
    }
    n := len(rec)
    for i := n - 1;i >= 0;i-- {
        rmx,idx := rec[i],i
        for j := i - 1;j >= 0;j-- {
            if rec[j] >= rmx {
                rmx = rec[j]
                idx = j
            }
        }
        if rmx > rec[i] {
            rec[i],rec[idx] = rec[idx],rec[i]
            break
        }
    }
    ans := 0
    for i := n - 1;i >= 0;i-- {
        ans = ans * 10 + rec[i]
    }
    return ans
}
