from typing import List

class Solution:
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        ans = [0] * n
        for _,bk in enumerate(bookings):
            l,r,w = bk[0],bk[1],bk[2]
            ans[l - 1] += w
            if r < n: ans[r] -= w
        for i in range(1,n):
            ans[i] += ans[i - 1]
        return ans