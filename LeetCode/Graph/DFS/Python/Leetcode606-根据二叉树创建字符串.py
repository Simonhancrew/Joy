class Solution:
    def tree2str(self, root: Optional[TreeNode]) -> str:
        res = []

        def dfs(root):
            if not root: return
            res.append(str(root.val))
            if root.left or (not root.left and root.right):
                res.append('(')
                dfs(root.left)
                res.append(')')
            if root.right:
                res.append('(')
                dfs(root.right)
                res.append(')')

        dfs(root)
        return ''.join(res)
