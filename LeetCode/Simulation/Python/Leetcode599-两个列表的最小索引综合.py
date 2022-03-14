class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        ans,mp = [],defaultdict(int)
        for i in range(len(list1)): mp[list1[i]] = i
        tot = int(1e9 + 10)
        for i in range(len(list2)):
            s = list2[i]
            if s in mp:
                k = i + mp[s]
                if k < tot:
                    ans = [s]
                    tot = k
                elif k == tot:
                    ans.append(s)
        return ans