class Solution:
    def countSegments(self, s: str) -> int:
        cnt,i,n = 0,0,len(s)
        while i < len(s):
            while i < len(s) and s[i] == ' ': i += 1
            if i == len(s): break
            while i < n and s[i] != ' ': i += 1
            cnt += 1
        return cnt
