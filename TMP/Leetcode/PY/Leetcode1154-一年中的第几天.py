class Solution:
    def dayOfYear(self, date: str) -> int:
        arr = date.split('-')
        y,m,d = int(arr[0]),int(arr[1]),int(arr[2])
        nums = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        is_leap = True if y % 400 == 0 or (y % 4 == 0 and y % 100 != 0) else False
        ans = 0
        for i in range(m - 1):
            ans += nums[i]
            if is_leap and i == 1:
                ans += 1
        return ans + d
