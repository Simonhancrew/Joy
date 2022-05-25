class Solution:
    def findSubstringInWraproundString(self, p: str) -> int:
        mp = defaultdict(int)
        i = 0
        while i < len(p):
            j = i + 1
            while j < len(p) and ((ord(p[j]) - ord(p[j - 1]) == 1) or (p[j] == 'a' and p[j - 1] == 'z')): 
                print(j)
                j += 1
            while i < j: 
                mp[p[i]] = max(mp[p[i]],j - i)
                i += 1
        res = 0
        for k,v in mp.items():
            res += v
        return res