class Solution:
    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        def dfs(node,x):
            if not node: return x 
            x = x * 2 + node.val
            if not node.left and not node.right: return x
            tmp = 0
            if node.left: tmp += dfs(node.left,x)
            if node.right: tmp += dfs(node.right,x)
            return tmp
        
        
        return dfs(root,0)