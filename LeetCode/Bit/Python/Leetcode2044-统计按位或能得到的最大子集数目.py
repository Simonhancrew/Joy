class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        ans, n, mxor = 0, len(nums), 0
        for i in range(1, (1 << n)):
            cur = 0
            for j in range(n):
                if (i >> j) & 1 == 1: cur |= nums[j]
            if mxor == cur:
                ans += 1
            elif cur > mxor:
                mxor = cur
                ans = 1
        return ans
