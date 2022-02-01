package sbgo 

func longestNiceSubstring(s string) string {
    start,length,n := 0,0,len(s)
    for l := 0;l < n;l++ {
        a,b := 0,0
        for r := l;r < n;r++ {
            if s[r] >= 'a' && s[r] <= 'z'{
                a |= 1 << (s[r] - 'a')
            }else {
                b |= 1 << (s[r] - 'A')
            }
            if a == b && r - l + 1 > length {
                length = r - l + 1
                start = l
            }
        }
    }
    return s[start:start + length]
}