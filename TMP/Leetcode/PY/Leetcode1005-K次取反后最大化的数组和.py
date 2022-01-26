class Solution:
    def largestSumAfterKNegations(self, nums: List[int], k: int) -> int:
        mp = defaultdict(int)
        mn = int(1000)
        for num in nums:
            mp[num] += 1
            mn = min(mn,abs(num))
        for i in range(-100,0):
            if k == 0: break
            while k > 0 and i in mp and mp[i] != 0:
                mp[i] -= 1
                mp[-i] += 1
                k -= 1
        res = 0
        for i in range(-100,101):
            if i in mp and mp[i] > 0: res += mp[i] * i

        if k & 1 == 1: res -= 2 * mn
        return res