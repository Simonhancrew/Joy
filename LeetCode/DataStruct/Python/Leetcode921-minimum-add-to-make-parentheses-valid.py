class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        l, r = 0, 0
        for c in s:
            if c == '(': l += 1
            elif c == ')':
                if not l: r += 1
                else: l -= 1
        return l + r
