class Solution:
    def numSubarrayBoundedMax(self, nums: List[int], left: int, right: int) -> int:
        n = len(nums)
        def calcu(mx):
            nonlocal n
            res, i = 0,0
            while i < n:
                if nums[i] > mx:
                    i += 1
                    continue
                j = i + 1
                while j < n and nums[j] <= mx: j += 1
                dis = j - i
                res += (dis + 1) * dis // 2
                i = j + 1
            return res
        return calcu(right) - calcu(left - 1) 