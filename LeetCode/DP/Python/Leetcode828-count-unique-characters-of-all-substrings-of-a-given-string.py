class Solution:
    def uniqueLetterString(self, s: str) -> int:
        n = len(s)
        l, r, last = [0] * n, [0] * n, [-1] * 26
        for i in range(n):
            l[i] = last[ord(s[i]) - ord('A')]
            last[ord(s[i]) - ord('A')] = i
        last = [n] * 26
        for i in range(n - 1, -1, -1):
            r[i] = last[ord(s[i]) - ord('A')]
            last[ord(s[i]) - ord('A')] = i
        ans = 0
        for i in range(n):
            ans += (i - l[i]) * (r[i] - i)
        return ans
