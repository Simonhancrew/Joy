from typing import List

class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
        path = ['0'] * 100
        res = []

        def dfs(u,leng,a,b):
            if u == len(num):
                if a == target: res.append(''.join(path[0:leng - 1]))
                return
            c = 0
            for i in range(u,len(num)):
                c = c * 10 + int(num[i])
                path[leng] = num[i]
                leng += 1

                path[leng] = '+'
                dfs(i + 1,leng + 1,a + b * c,1)
                if i + 1 < len(num):
                    path[leng] = '-'
                    dfs(i + 1,leng + 1,a+b*c,-1)

                    path[leng] = '*'
                    dfs(i + 1,leng + 1,a,b * c)
                if num[u] == '0': break 

        dfs(0,0,0,1)
        return res