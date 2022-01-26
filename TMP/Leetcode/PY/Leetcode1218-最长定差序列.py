class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        f = defaultdict(int)
        ans = 1
        for a in arr:
            f[a] = f[a - difference] + 1
            ans = max(ans,f[a])
        return ans