class Solution:
    def digitCount(self, num: str) -> bool:
        mp = [0] * 10
        for i in num:
            mp[ord(i) - ord('0')] += 1
        for i in range(len(num)):
            cnt = int(num[i])
            if cnt != mp[i]:
                return False
        return True
