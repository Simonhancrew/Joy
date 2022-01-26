class Solution:
    def checkValidString(self, s: str) -> bool:
        cnt1,cnt2 = 0,0
        for i in range(len(s)):
            if s[i] == '(': 
                cnt1 += 1
                cnt2 += 1
            elif s[i] == '*':
                cnt1 -= 1
                cnt2 += 1
            else:
                cnt1 -= 1
                cnt2 -= 1
            cnt1 = max(0,cnt1)
            if cnt1 > cnt2: return False    
        return cnt1 == 0