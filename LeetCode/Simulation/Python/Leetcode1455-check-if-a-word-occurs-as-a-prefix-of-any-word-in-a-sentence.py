class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        rec,idx,ans = sentence.split(' '),0,-1
        print(rec)
        def check(s,p):
            if len(p) > len(s): return False
            for i in range(len(p)):
                if s[i] != p[i]: return False
            return True
        for s in rec:
            idx += 1
            if check(s,searchWord):
                ans = idx
                break
        return ans