class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        l, r = [0] * n, [0] * n
        l[0], r[n - 1] = height[0], height[-1]
        for i in range(1, n):
            l[i] = max(l[i - 1], height[i])
        for i in range(n - 2, 0, -1):
            r[i] = max(r[i + 1], height[i])
        ans = 0
        for i in range(1, n - 1):
            ans += min(l[i], r[i]) - height[i]
        return ans