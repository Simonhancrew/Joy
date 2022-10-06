class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        ans, level, layer = int(-1e9), 0, 0
        q = deque([root])
        while q:
            n, cur = len(q), 0
            layer += 1
            for i in range(n):
                t = q.popleft()
                cur += t.val
                if t.left: q.append(t.left)
                if t.right: q.append(t.right)
            if cur > ans:
                ans = cur
                level = layer
        return level
