package sbgo

func minimumMoves(s string) int {
    ans, n := 0, len(s)
    for i := 0;i < n;i++ {
        if s[i] == 'O' {
            continue
        }
        ans++
        i += 2
    }
    return ans
}
