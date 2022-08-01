package sbgo

func generateTheString(n int) string {
    if n % 2 == 0 {
        return strings.Repeat("a",n - 1) + "b"
    }
    if n == 1 {
        return "a"
    }
    return strings.Repeat("a",n - 2) + "b" + "c"
}
