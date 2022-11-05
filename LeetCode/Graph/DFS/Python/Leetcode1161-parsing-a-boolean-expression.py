class Solution:
    def parseBoolExpr(self, s: str) -> bool:
        n, i = len(s), 0
        def dfs():
            nonlocal i
            if s[i] == 't': 
                i += 1
                return True
            if s[i] == 'f':
                i += 1
                return False
            # op
            op = s[i]
            i += 2
            res = True
            if op == '|': res = False
            while s[i] != ')':
                if s[i] == ',': i += 1
                t = dfs()
                if op == '|': res |= t
                else: res &= t
            i += 1
            if op == '!': res = not res
            return res
        return dfs()