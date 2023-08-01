class Solution:
    def sumOfPower(self, nums: List[int]) -> int:
        ans, s = 0, 0
        nums.sort()
        MOD = int(1e9) + 7
        for x in nums:
            ans = (ans + x * x * (x + s)) % MOD
            s = (s * 2 + x) % MOD
        return ans