class Solution:
    def dayOfTheWeek(self, day: int, month: int, year: int) -> str:
        cnt = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30]
        ans = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday","Sunday"]
        days = 0
        for i in range(1971,year):
            days += 366 if (i % 400 == 0 or (i % 4 == 0 and i % 100 != 0)) else 365
        for i in range(0,month-1):
            days += cnt[i]
        if month > 2 and (year % 400 == 0 or (year % 4  == 0 and year % 100 != 0)):
            days += 1
        days += day
        return ans[(days + 3) % 7]