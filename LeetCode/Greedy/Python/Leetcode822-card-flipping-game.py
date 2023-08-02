class Solution:
    def flipgame(self, fronts: List[int], backs: List[int]) -> int:
        st = set()
        n = len(fronts)
        ans = 40000
        for i in range(n):
            if fronts[i] == backs[i]:
                st.add(fronts[i])
        for i in range(n):
            if fronts[i] not in st:
                ans = min(ans, fronts[i])
            if backs[i] not in st:
                ans = min(ans, backs[i])
        if ans == 40000: 
            return 0
        return ans