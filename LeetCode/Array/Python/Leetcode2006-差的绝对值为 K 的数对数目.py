class Solution:
    def countKDifference(self, nums: List[int], k: int) -> int:
        ans,mp = 0,defaultdict(int)
        for num in nums:
            ans += mp[num - k] if num - k in mp else 0
            ans += mp[num + k] if num + k in mp else 0
            mp[num] += 1
        return ans