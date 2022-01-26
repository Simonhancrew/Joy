class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        mp = defaultdict(int)
        n,m = len(s),len(p)
        for ch in p: mp[ch] += 1
        tot = len(mp)
        res = []
        i,j,sa = 0,0,0
        while j < n:
            if s[j] in mp:
                mp[s[j]] -= 1
                if mp[s[j]] == 0: sa += 1
            if j - i + 1 == m:
                if sa == tot: res.append(i)
                if s[i] in mp:
                    if mp[s[i]] == 0: sa -= 1
                    mp[s[i]] += 1
                i += 1
            j += 1
        return res