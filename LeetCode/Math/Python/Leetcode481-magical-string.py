class Solution:
    def magicalString(self, n: int) -> int:
        s = "122"
        s = list(s)
        i, k = 2, 1
        while len(s) < n:
            r = ord(s[i]) - ord('0')
            for j in range(r):
                s.append(str(k))
            i += 1
            k = 3 - k
        res = 0
        for i in range(n):
            res += 1 if s[i] == '1' else 0
        return res
