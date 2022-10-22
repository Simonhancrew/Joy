class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        n, arr = len(startTime), []
        for i in range(n):
            arr.append([startTime[i], endTime[i], profit[i]])
        arr.sort(key = lambda x : x[1]) 
        f = [0] * n
        f[0] = arr[0][2]
        for i in range(1, n):
            f[i] = max(f[i - 1], arr[i][2])
            if arr[0][1] <= arr[i][0]:
                l,r = 0, i - 1
                while l < r:
                    mid = l + r + 1 >> 1
                    if arr[mid][1] <= arr[i][0]: l = mid
                    else: r = mid - 1
                f[i] = max(f[i], f[r] + arr[i][2])
        return f[n - 1]