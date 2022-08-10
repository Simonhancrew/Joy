class Solution:
    def solveEquation(self, equation: str) -> str:
        l,r = equation.split('=')
        def get(s):
            a,b,i = 0,0,0
            if s[0] != '+' and s[0] != '-': s = '+' + s
            while i < len(s):
                j = i + 1
                while j < len(s) and s[j].isdigit(): j += 1
                c = 1
                if i + 1 <= j - 1: c = int(s[i + 1 : j])
                if s[i] == '-': c = -c
                if j < len(s) and s[j] == 'x':
                    a += c 
                    i = j
                else:
                    b += c
                    i = j - 1
                i += 1
            return [a,b]
    
        lhs,rhs = get(l),get(r)
        a,b = lhs[0] - rhs[0],rhs[1] - lhs[1]
        if not a:
            if not b: return 'Infinite solutions'
            else: return 'No solution'
        return 'x=' + str(b // a)