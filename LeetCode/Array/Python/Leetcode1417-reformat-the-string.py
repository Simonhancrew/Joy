class Solution:
    def reformat(self, s: str) -> str:
        cnt,n = 0,len(s)
        for i in range(n):
            if s[i].isdigit(): cnt += 1
        if abs(cnt - (n - cnt)) > 1: return ''
        flag = cnt > (n - cnt)
        s = list(s)
        j = 1
        for i in range(0,n,2):
            if s[i].isdigit() != flag:
                while s[j].isdigit() != flag: j += 2
                s[i],s[j] = s[j],s[i]
        return ''.join(s)