class Solution:
    def longestUnivaluePath(self, root: Optional[TreeNode]) -> int:
        res = 0
        def dfs(node):
            nonlocal res
            if not node: return 0
            l,r = dfs(node.left),dfs(node.right)
            ll = l + 1 if node.left and node.left.val == node.val else 0
            rr = r + 1 if node.right and node.right.val == node.val else 0
            res = max(res,ll + rr)
            return max(ll,rr)
        dfs(root)
        return res
