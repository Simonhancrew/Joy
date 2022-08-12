class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        mp,n = defaultdict(list),len(groupSizes)
        for i in range(n):
            mp[groupSizes[i]].append(i)
        ans = []
        for k,v in mp.items():
            rhs = len(v)
            for i in range(0,rhs,k):
                cur = v[i:i + k]
                ans.append(cur)
        return ans