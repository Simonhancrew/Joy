class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        s = list('L' + dominoes + 'R')
        n,j = len(s),0
        l,r = [0] * n,[0] * n 
        for i in range(n):
            if s[i] != '.': j = i
            l[i] = j
        j = 0
        for i in range(n - 1,-1,-1):
            if s[i] != '.': j = i
            r[i] = j
        for i in range(n):
            lhs,rhs = s[l[i]],s[r[i]]
            if lhs == 'L' and rhs == 'R': s[i] = '.'
            elif lhs == 'L' and rhs == 'L': s[i] = 'L'
            elif lhs == 'R' and rhs == 'R': s[i] = 'R'
            else:
                if i - l[i] < r[i] - i: s[i] = 'R'
                elif i - l[i] > r[i] - i: s[i] = 'L'
                else: s[i] = '.'
        return ''.join(s[1:-1])