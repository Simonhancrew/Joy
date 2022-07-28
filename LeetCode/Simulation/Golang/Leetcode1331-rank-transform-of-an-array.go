package sbgo

func arrayRankTransform(arr []int) []int {
    n := len(arr)
    tmp := make([]int,n)
    copy(tmp,arr)
    sort.Ints(tmp)
    mp := make(map[int]int)
    for i,cnt := 0,1;i < n;i++ {
        if _,ok := mp[tmp[i]];!ok {
            mp[tmp[i]] = cnt
            cnt++
        }
    }
    // for i := 0;i < n;i++ {
    //     fmt.Println(arr[i])
    // }
    ans := make([]int,n)
    for i := 0;i < n;i++ {
        ans[i] = mp[arr[i]]
    }
    return ans
}