class Solution:
    def minimumMoves(self, s: str) -> int:
        n, i = len(s), 0
        ans = 0 
        while i < n:
            if s[i] == 'O': 
                i += 1
                continue
            i += 3
            ans += 1
        return ans
