class Solution:
    def convertToBase7(self, num: int) -> str:
        if num == 0: return '0'
        ans,flag = [],False
        if num < 0:
            num = -num
            flag = True
        while num != 0:
            ans.append(str(num % 7))
            num //= 7
        if flag: ans.append('-')
        ans = ans[::-1]
        return ''.join(ans) 