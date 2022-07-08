class Solution:
    def minCostToMoveChips(self, position: List[int]) -> int:
        o,e = 0,0
        for p in position:
            if p % 2: o += 1
            else: e += 1
        if not e or not o: return 0
        return min(o,e)