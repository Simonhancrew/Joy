class Solution:
    def canReorderDoubled(self, arr: List[int]) -> bool:
        mp = Counter(arr)
        rec = []
        if mp[0] % 2 != 0: return False
        for k in sorted(mp, key=abs):
            if mp[k * 2] < mp[k]:
                return False
            mp[k * 2] -= mp[k]
        return True
