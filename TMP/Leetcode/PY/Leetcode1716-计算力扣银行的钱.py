class Solution:
    def totalMoney(self, n: int) -> int:
        ans,cnt = 0,1
        for i in range(n):
            if i != 0 and i % 7 == 0: cnt += 1
            ans += (cnt + i % 7)
        return ans