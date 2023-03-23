package sbgo

func checkArithmeticSubarrays(nums []int, l []int, r []int) []bool {
    n := len(r)
    res := make([]bool, n)
    check := func(s []int, idx int) {
        n := len(s)
        flag := true
        for i := 1;i < n - 1;i++ {
            if s[i + 1] - s[i] == s[1] - s[0] {
                continue
            }
            flag = false;
            break
        }
        res[idx] = flag
    }
    for i := 0;i < n;i++ {
        cp := make([]int, r[i] - l[i] + 1)
        idx := 0;
        for j := l[i];j <= r[i];j++ {
            cp[idx] = nums[j]
            idx++
        }
        sort.Ints(cp)
        check(cp, i)
    }
    return res
}


