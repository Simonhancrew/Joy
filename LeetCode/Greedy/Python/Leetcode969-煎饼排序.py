class Solution:
    def pancakeSort(self, arr: List[int]) -> List[int]:
        n, res = len(arr), []

        def rev(l, r):
            while l < r:
                arr[l], arr[r] = arr[r], arr[l]
                l += 1
                r -= 1

        for i in range(n - 1, -1, -1):
            mx = 0
            for j in range(0, i + 1):
                if arr[j] > arr[mx]: mx = j
            if mx == i: continue
            rev(0, mx)
            res.append(mx + 1)
            rev(0, i)
            res.append(i + 1)
        return res
