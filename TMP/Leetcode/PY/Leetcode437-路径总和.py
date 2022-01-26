class Solution:
    def pathSum(self, root: TreeNode, targetSum: int) -> int:
        if not root: return 0
        def dfs(root,targetSum):
            if not root: return 0
            if root.left == None and root.right == None:
                return 1 if root.val == targetSum else 0
            cnt = 1 if targetSum == root.val else 0
            return dfs(root.left,targetSum-root.val) + dfs(root.right,targetSum - root.val) + cnt

        return self.pathSum(root.left,targetSum) + self.pathSum(root.right,targetSum) + dfs(root,targetSum)