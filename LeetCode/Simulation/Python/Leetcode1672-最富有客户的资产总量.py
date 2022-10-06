class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        mx = 0
        for x in accounts:
            cur = sum(x)
            mx = max(mx, cur)
        return mx
