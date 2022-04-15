class Solution:
    def __init__(self):
        self.u = 0
    def deserialize(self, s: str) -> NestedInteger:
        def dfs(s):
            res = NestedInteger()
            if s[self.u] == '[':
                self.u += 1
                while s[self.u] != ']': res.add(dfs(s))
                self.u += 1
                if self.u < len(s) and s[self.u] == ',':
                    self.u += 1
            else:
                k = self.u
                while k < len(s) and s[k] != ']' and s[k] != ',':
                    k += 1
                res.setInteger(int(s[self.u:k]))
                if k < len(s) and s[k] == ',':
                    k += 1
                self.u = k        
            return res

        return dfs(s)