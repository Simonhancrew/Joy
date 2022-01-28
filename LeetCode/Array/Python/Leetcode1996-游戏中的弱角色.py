class Solution:
    def numberOfWeakCharacters(self, ps: List[List[int]]) -> int:
        ps.sort(key = lambda x : (-x[0],x[1]))
        ans,mx = 0,0
        for _,se in ps:
            if se < mx: ans += 1
            else: mx = max(mx,se)
        return ans