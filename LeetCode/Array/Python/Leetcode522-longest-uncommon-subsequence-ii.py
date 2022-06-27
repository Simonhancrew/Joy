class Solution:
    def findLUSlength(self, strs: List[str]) -> int:
        n,res = len(strs),-1
        def check(a,b):
            n,m = len(b),len(a)
            j = 0
            for i in range(n):
                if j < m and a[j] == b[i]:
                    j += 1
            return j == m
        for i in range(n):
            flag = False
            for j in range(n):
                if i != j and check(strs[i],strs[j]):
                    flag = True
                    break
            if not flag: res = max(res,len(strs[i]))
        return res