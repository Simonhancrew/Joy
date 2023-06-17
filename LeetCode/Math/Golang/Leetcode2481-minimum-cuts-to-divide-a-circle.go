package sbgo

func numberOfCuts(n int) int {
    if n == 1 {
        return 0
    }
    if n & 1 == 0 {
        return n / 2
    }
    return n
}
