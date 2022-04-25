class Solution:

    def __init__(self, nums: List[int]):
        self.nums = nums

    def pick(self, target: int) -> int:
        cnt,res,n = 0,0,len(self.nums)
        nums = self.nums
        for i in range(n):
            if nums[i] == target:
                cnt += 1
                if randint(0,cnt - 1) == 0:
                    res = i
        return res
