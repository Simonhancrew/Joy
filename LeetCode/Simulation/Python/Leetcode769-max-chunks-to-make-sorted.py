class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        n, res, mx = len(arr), 0, 0
        for k,v in enumerate(arr):
            mx = max(mx, v)
            res += 1 if mx == k else 0
        return res
