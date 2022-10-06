class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        nums.sort()
        n, res = len(nums), 0
        for x in range(n):
            res += abs(nums[x] - nums[n // 2])
        return res
