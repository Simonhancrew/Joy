class Solution:
    def lenLongestFibSubseq(self, arr: List[int]) -> int:
        res,n,mp = 0,len(arr),defaultdict(int)
        f = [[0] * n for _ in range(n)] 
        for i in range(n):mp[arr[i]] = i
        for i in range(n):
            for j in range(i):
                x = arr[i] - arr[j]
                f[i][j] = 2
                if x < arr[j] and x in mp:
                    k = mp[x]
                    f[i][j] = max(f[i][j],f[j][k] + 1)
                res = max(res,f[i][j])
        if res < 3:
            return 0
        return res