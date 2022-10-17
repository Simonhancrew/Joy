class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        mp,res,n = defaultdict(int), 0, len(fruits)
        j,s = 0,0
        for i in range(n):
            mp[fruits[i]] += 1
            if mp[fruits[i]] == 1: s += 1
            while s > 2:
                mp[fruits[j]] -= 1
                if mp[fruits[j]] == 0:
                    s -= 1
                j += 1
            res = max(res, i - j + 1)
        return res
