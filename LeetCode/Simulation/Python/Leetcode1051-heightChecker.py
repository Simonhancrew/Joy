class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        rec,ans = heights[:],0
        rec.sort()
        for i in range(len(rec)):
            if rec[i] != heights[i]:
                ans += 1
        return ans