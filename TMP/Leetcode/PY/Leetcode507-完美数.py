class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        if num == 1: return False
        ans = 0
        for i in range(1,int(sqrt(num)) + 1):
            if num % i == 0: ans += i
            t = num // i
            if t != num and t != i and num % t == 0: ans += t
        return ans == num