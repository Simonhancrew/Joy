class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        f = word.split()
        def check(s):
            n,cnt = len(s),0
            for ch in s:
                if ch.isupper(): cnt += 1
            if cnt == 0 or cnt == n: return True
            if cnt == 1 and s[0].isupper(): return True
            return False
        for s in f:
            if not check(s): return False
        return True
