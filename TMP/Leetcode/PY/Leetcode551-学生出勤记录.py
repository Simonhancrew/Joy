class Solution:
    def checkRecord(self, s: str) -> bool:
        if 'LLL' in s:
            return False
        cnt = 0
        for ch in s:
            if ch == 'A':
                cnt += 1
        if cnt >= 2:
            return False
        return True


# class Solution:
#     def checkRecord(self, s: str) -> bool:
#         return s.count('A') < 2 and not('LLL' in s)