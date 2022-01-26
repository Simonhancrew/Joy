class Solution:
    def repeatedStringMatch(self, a: str, b: str) -> int:
        s,i = a,1
        while len(s) < len(b):
            s += a
            i += 1
        if s.find(b) != -1: return i
        else:
            i += 1
            s += a
            if s.find(b) != -1:
                return i
        return -1