class Solution:
    def buddyStrings(self, s: str, goal: str) -> bool:
        if len(s) != len(goal): return False
        if s == goal:
            mp = defaultdict(int)
            for ch in s:
                mp[ch]+=1
                if mp[ch] > 1: return True
            return False
        idx = []
        for i in range(len(s)):
            if s[i] != goal[i]:
                idx.append(i)
        if len(idx) != 2: return False
        x,y = idx[0],idx[1]
        return s[x] == goal[y] and s[y] == goal[x]
