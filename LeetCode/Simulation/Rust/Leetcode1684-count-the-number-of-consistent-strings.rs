func countConsistentStrings(allowed string, words []string) int {
    ans, mask := 0, 0
    for _, c := range allowed {
        mask |= 1 << int(c - 'a')
    }
    for _, word := range words {
        cur := 0
        for _, c := range word {
            cur |= 1 << int(c - 'a')
        }
        if (mask | cur) == mask {
            ans++
        }
    }
    return ans
}
