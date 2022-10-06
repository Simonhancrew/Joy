class Solution:
    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        l, r = 0, int(1e6)
        nums.sort()

        def get(mid):
            res, j = 0, 0
            for i in range(len(nums)):
                while nums[i] - nums[j] > mid:
                    j += 1
                res += i - j
            return res

        while l < r:
            mid = l + r >> 1
            if get(mid) >= k: r = mid
            else: l = mid + 1
        return r
