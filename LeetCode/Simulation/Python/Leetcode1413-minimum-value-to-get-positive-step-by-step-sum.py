class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        acc, ans = 0, 1
        for num in nums:
            acc += num
            nag = 1 - acc
            if nag > ans: ans = nag
        return ans
