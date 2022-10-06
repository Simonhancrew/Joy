class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        b, n = arr[:], len(arr)
        b.sort()
        res, s, mp = 0, 0, defaultdict(int)
        for i in range(n):
            if mp[arr[i]] == 1: s -= 1
            elif mp[arr[i]] == 0: s += 1
            mp[arr[i]] -= 1
            if mp[b[i]] == -1: s -= 1
            elif mp[b[i]] == 0: s += 1
            mp[b[i]] += 1
            if not s: res += 1
        return res
