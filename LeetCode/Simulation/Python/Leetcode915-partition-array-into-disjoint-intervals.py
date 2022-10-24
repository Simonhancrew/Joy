class Solution:
    def partitionDisjoint(self, nums: List[int]) -> int:
        n = len(nums)
        lmx, rmn = [0] * n, [0] * n
        lmx[0], rmn[n - 1] = nums[0], nums[n - 1]
        for i in range(1, n):
            lmx[i] = max(lmx[i - 1], nums[i])
        for i in range(n - 2, -1, -1):
            rmn[i] = min(rmn[i + 1], nums[i])
        ans = 1
        for i in range(0, n - 1):
            if lmx[i] <= rmn[i + 1]: break
            ans += 1
        return ans
