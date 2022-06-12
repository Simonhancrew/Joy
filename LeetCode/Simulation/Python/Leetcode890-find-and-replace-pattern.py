class Solution:
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        n,ans = len(pattern),[]
        for s in words:
            if len(s) != n: continue
            mp,vis = [-1] * 26,[False] * 26
            ok = True
            for i in range(n):
                l,r = ord(s[i]) - ord('a'),ord(pattern[i]) - ord('a')
                if mp[l] == -1 and not vis[r]:
                    mp[l],vis[r] = r,True
                elif mp[l] != r:
                    ok = False
                    break 
            if ok: ans.append(s)
        return ans