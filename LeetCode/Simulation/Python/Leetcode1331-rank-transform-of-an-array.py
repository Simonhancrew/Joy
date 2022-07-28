class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        rank = {v : i for i,v in enumerate(sorted(set(arr)),1)}
        return [rank[v] for v in arr]