class Solution:
    def diStringMatch(self, s: str) -> List[int]:
        n = len(s)
        ans, l, r = [0] * (n + 1), 0, n
        for i in range(n):
            if s[i] == 'I': ans[i], l = l, l + 1
            else: ans[i], r = r, r - 1
        ans[n] = l
        return ans
