class Solution:
    def isValid(self, s: str) -> bool:
        stk = []
        for c in s:
            stk.append(c)
            if len(stk) >= 3 and ''.join(stk[len(stk) - 3:]) == 'abc':
                stk = stk[:-3]
        return len(stk) == 0