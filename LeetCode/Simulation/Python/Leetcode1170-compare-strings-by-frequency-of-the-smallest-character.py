class Solution:
    def numSmallerByFrequency(self, queries: List[str], words: List[str]) -> List[int]:
        n, m = len(queries), len(words)
        f, ans = [0] * m, [0] * n

        def get(word):
            mn = word[0]
            mp = defaultdict(int)
            for x in word:
                if mn > x:
                    mn = x
                mp[x] += 1
            return mp[mn]
        
        def check(x):
            nonlocal f
            nonlocal get
            res, cur = 0, get(x)
            for y in f:
                if cur < y: res += 1
            return res

        for i in range(m):
            f[i] = get(words[i])
        for i in range(n):
            ans[i] = check(queries[i])

        return ans