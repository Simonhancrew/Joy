class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        INF = (1 << 31) - 1
        f = [INF] * 2
        for n in nums:
            k = 2
            while k > 0 and f[k - 1] >= n: k -= 1
            if k == 2: return True
            f[k] = n
        return False