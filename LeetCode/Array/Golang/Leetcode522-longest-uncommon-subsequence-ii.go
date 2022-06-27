package sbgo

func findLUSlength(strs []string) int {
    n,res := len(strs),-1
    check := func(a,b string) bool {
        n,_ := len(a),len(b)
        i := 0
        for _,ch := range b {
            if i < n && ch == rune(a[i]) {
                i++
            }
        }
        return i == n
    }
    for i := 0;i < n;i++ {
        flag := false
        for j := 0;j < n;j++ {
            if i != j && check(strs[i],strs[j]) {
                flag = true;
                break
            }
        }
        if !flag {
            if res < len(strs[i]){
                res = len(strs[i])
            }
        }
    }
    return res
}