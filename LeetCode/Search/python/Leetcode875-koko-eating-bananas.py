class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l, r = 1, max(piles)

        def check(k):
            cnt = 0
            for pile in piles:
                if pile <= k: cnt += 1
                else: cnt += (pile + k - 1) // k
            return cnt <= h

        while l < r:
            mid = (l + r) >> 1
            if check(mid): r = mid
            else: l = mid + 1
        return l
