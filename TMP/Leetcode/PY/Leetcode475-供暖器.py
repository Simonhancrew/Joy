class Solution:
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        l,r = 0,int(1e9)
        houses.sort()
        heaters.sort()
        def check(length):
            i,j = 0,0
            while (i < len(houses)):
                while j < len(heaters) and abs(houses[i] - heaters[j]) > length:
                    j += 1
                if j >= len(heaters):
                    return False
                i += 1
            return True
        while l < r:
            mid = l + r >> 1
            if(check(mid)): r = mid
            else: l = mid + 1
        return r