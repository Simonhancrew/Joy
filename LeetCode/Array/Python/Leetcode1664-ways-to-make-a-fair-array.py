class Solution:
    def waysToMakeFair(self, nums: List[int]) -> int:
        n = len(nums)
        s1, s2 = [0] * (n + 1), [0] * (n + 1)
        for i in range(1, n + 1):
            s1[i], s2[i] = s1[i - 1], s2[i - 1]
            if i % 2 == 1: s1[i] += nums[i - 1]
            else: s2[i] += nums[i - 1]
        res = 0
        for i in range(1, n + 1):
            odd, even = s1[i - 1] + s2[n] - s2[i], s2[i - 1] + s1[n] - s1[i]
            if odd == even: res += 1
        return res