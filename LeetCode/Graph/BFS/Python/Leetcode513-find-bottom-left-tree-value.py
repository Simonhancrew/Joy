class Solution:
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        val,height = 0,0
        def dfs(node,h):
            nonlocal val,height
            if not node:
                return
            h += 1
            dfs(node.left,h)
            dfs(node.right,h)
            if h > height:
                height = h
                val = node.val
        dfs(root,0)
        return val