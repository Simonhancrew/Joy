class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        l,r = 0,len(arr) - 1
        while l < r:
            mid = (l + r) >> 1
            if arr[mid] > x: r -= 1
            else: l += 1
        l = r - 1
        for _ in range(k):
            if l < 0: r += 1
            elif r >= len(arr) or x - arr[l] <= arr[r] - x: l -= 1
            else: r += 1
        return arr[l + 1:r]