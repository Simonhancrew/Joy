package sbgo

func findKthNumber(n int, k int) int {
    pre := 1
    f := func(pre,n int) int {
        a,b := strconv.Itoa(n),strconv.Itoa(pre)
        d := len(a) - len(b)
        res,p := 0,1
        for i := 0;i < d;i++ {
            res += p
            p *= 10
        }
        if a[0:len(b)] == b {
            res += n - pre * p + 1
        }else if a[0:len(b)] > b {
            res += p
        }
        return res
    }
    for k > 1 {
        cnt := f(pre,n)
        if k > cnt {
            k -= cnt
            pre++
        }else{
            k--
            pre *= 10
        }
    }
    return pre
}