class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        pairs.sort()
        n,ans = len(pairs),0
        f = [1] * n
        for i in range(1,n):
            for j in range(0,i):
                if pairs[i][0] > pairs[j][1]: f[i] = max(f[i],f[j] + 1)
        for i in range(n):
            ans = max(ans,f[i])
        return ans
