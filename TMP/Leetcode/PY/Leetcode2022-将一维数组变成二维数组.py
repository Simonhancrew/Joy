class Solution:
    def construct2DArray(self, original: List[int], m: int, n: int) -> List[List[int]]:
        if m * n != len(original): return []
        ans = []
        for i in range(m):
            t = []
            for j in range(n):
                t.append(original[i * n + j])
            ans.append(t)
        return ans