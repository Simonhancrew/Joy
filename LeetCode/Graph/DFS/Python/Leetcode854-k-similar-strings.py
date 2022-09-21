class Solution:
    def kSimilarity(self, s1: str, s2: str) -> int:
        n = len(s1)
        if s1 == s2: return 0
        dep = 1
        s1,s2 = list(s1),list(s2)
        
        def f(s1,s2):
            res = 0
            for i in range(n):
                if s1[i] != s2[i]: res += 1
            return (res + 1) // 2
        def dfs(s1,s2,dep):
            if not dep: return s1 == s2
            if f(s1,s2) > dep: return False
            for i in range(n):
                if s1[i] != s2[i]:
                    for j in range(i + 1,n):
                        if s2[i] == s1[j]:
                            s1[i],s1[j] = s1[j],s1[i]
                            if dfs(s1,s2,dep - 1):
                                return True
                            s1[i],s1[j] = s1[j],s1[i]
                    break
            return False
        while not dfs(s1,s2,dep): 
            dep += 1
        return dep

# if __name__=='__main__':
#     s = Solution()
#     s1,s2 = 'ab','ba'
#     print(s.kSimilarity(s1,s2))
