class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        n, st, cnt = len(s) // 2, ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'], 0
        for i in range(n):
            if s[i] in st: cnt += 1
        for i in range(n, n * 2):
            if s[i] in st: cnt -= 1
            if cnt < 0: return False
        return cnt == 0