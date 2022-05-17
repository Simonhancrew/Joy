class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        mp = defaultdict(int)
        for i in range(len(order)):
            mp[order[i]] = i
        for i in range(1,len(words)):
            l,r = words[i - 1],words[i]
            x,y = 0,0
            while x < len(l) and y < len(r):
                if mp[l[x]] > mp[r[y]]: return False
                if mp[r[y]] > mp[l[x]]: break
                x,y = x + 1,y + 1
            if x < len(l) and y == len(r): return False
        return True