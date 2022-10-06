class Solution:
    def makesquare(self, arr: List[int]) -> bool:
        tot = sum(arr)
        if tot % 4 != 0: return False
        arr.sort(reverse=True)
        edge = [0] * 4

        def dfs(u):
            if u == len(arr): return True
            for i in range(4):
                edge[i] += arr[u]
                if edge[i] <= tot // 4 and dfs(u + 1):
                    return True
                edge[i] -= arr[u]
            return False

        return dfs(0)
