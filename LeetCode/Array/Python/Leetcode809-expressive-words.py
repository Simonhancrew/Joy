class Solution:
    def expressiveWords(self, s: str, words: List[str]) -> int:
        rec, n, i, ans = [], len(s), 0, 0
        while i < n:
            j = i + 1
            while j < n and s[i] == s[j]: j += 1
            rec.append([s[i], j - i])
            i = j

        def check(w):
            if len(w) > len(s): return False
            i, n, k = 0, len(w), 0 
            while i < n:
                if k == len(rec): return False
                if w[i] != rec[k][0]: return False
                j = i + 1
                while j < n and w[j] == w[i]: j += 1
                difw, difs = j - i, rec[k][1]
                if difs < difw: return False
                if difs < 3 and difw != difs: return False
                k, i = k + 1, j
            return k == len(rec)

        for w in words:
            if check(w): ans += 1
        return ans