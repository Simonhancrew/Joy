class Solution:
    def catMouseGame(self, g: List[List[int]]) -> int:
        n = len(g)
        f = [[[-1] * n for _ in range(n)] for _ in range(2 * n + 1)]
        def dp(k,i,j):
            nonlocal f
            if k > 2 * n:
                return 0
            v = f[k][i][j]
            if v != -1: return v
            if i == 0: 
                f[k][i][j] = 1
                return 1
            if i == j:
                f[k][i][j] = 2
                return 2
            draws = 0
            if k % 2 == 0:
                for x in g[i]:
                    t = dp(k + 1,x,j)
                    if t == 1: 
                        f[k][i][j] = 1
                        return 1
                    if t == 0: draws += 1
                if draws != 0: 
                    f[k][i][j] = 0
                    return 0 
                f[k][i][j] = 2
                return 2
            for x in g[j]:
                if x == 0: continue
                t = dp(k + 1,i,x)
                if t == 2:
                    f[k][i][j] = 2
                    return 2
                if t == 0: draws += 1
            if draws != 0: 
                f[k][i][j] = 0
                return 0
            f[k][i][j] = 1
            return 1
        return dp(0,1,2)