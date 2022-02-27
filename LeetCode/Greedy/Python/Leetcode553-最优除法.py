class Solution:
    def optimalDivision(self, nums: List[int]) -> str:
        n = len(nums)
        if n == 0: return ''
        if n == 1: return str(nums[0])
        if n == 2: return str(nums[0]) + '/' + str(nums[1])
        ans = str(nums[0]) + '('
        for i in range(1,n - 1):
            ans += str(nums[i]) + '/'
        ans += str(nums[n- 1]) + ')'
        return ans