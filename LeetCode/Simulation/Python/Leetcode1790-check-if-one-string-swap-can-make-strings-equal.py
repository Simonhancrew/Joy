class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        if s1 == s2: return True
        n,rec = len(s1),[]
        for i in range(n):
            if s1[i] != s2[i]:
                rec.append(i)
                if len(rec) > 2: return False 
        if len(rec) > 2 or len(rec) == 1: return False
        return s1[rec[0]] == s2[rec[1]] and s1[rec[1]] == s2[rec[0]]