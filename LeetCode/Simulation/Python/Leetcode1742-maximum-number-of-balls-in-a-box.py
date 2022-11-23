class Solution:
    def countBalls(self, lowLimit: int, highLimit: int) -> int:
        mp,ans = defaultdict(int), 0
        def calcu(x):
            res = 0
            while x:
                res += x % 10
                x //= 10
            return res
        for i in range(lowLimit, highLimit + 1):
            mp[calcu(i)] += 1
        for k,v in mp.items():
            ans = max(ans, v)
        return ans