class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        din,dout = [0] * (n + 1),[0] * (n + 1)
        for p in trust:
            a,b = p[0],p[1]
            din[b] += 1
            dout[a] += 1
        res = -1
        for i in range(1,n + 1):
            if dout[i] == 0 and din[i] == n - 1:
                if res != -1: 
                    return -1
                res = i
        return res