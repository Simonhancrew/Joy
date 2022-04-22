class Solution:
    def maxRotateFunction(self, nums: List[int]) -> int:
        acc,n,res = sum(nums),len(nums),0
        for i in range(n):
            res += i * nums[i]
        f = res 
        for i in range(n - 1,-1,-1):
            f += acc - n * nums[i]
            res = max(res,f)
        return res