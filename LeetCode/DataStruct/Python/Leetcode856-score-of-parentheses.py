class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        n,stk = len(s), [0]
        for i in range(n):
            if s[i] == '(': stk.append(0)
            else:
                t = stk.pop()
                if t == 0:
                    stk[-1] += 1
                else:
                    stk[-1] += 2 * t
        return stk[-1]        
