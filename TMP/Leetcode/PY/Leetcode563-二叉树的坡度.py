class Solution:
    ans = 0
    def findTilt(self, root: TreeNode) -> int:
        def dfs(root):
            if not root: return 0
            lhs,rhs = dfs(root.left),dfs(root.right)
            self.ans += abs(lhs - rhs)
            return lhs + rhs + root.val
        dfs(root)
        return self.ans