class Solution:
    def maximumSum(self, arr: List[int]) -> int:
        n = len(arr)
        f, g = [0] * n, [0] * n
        f[0], g[0] = arr[0], int(-1e5)
        ans = f[0]
        for i in range(1, n):
            f[i] = max(f[i - 1] + arr[i], arr[i])
            g[i] = max(g[i - 1] + arr[i], f[i - 1])
            ans = max(ans, f[i], g[i])
        return ans