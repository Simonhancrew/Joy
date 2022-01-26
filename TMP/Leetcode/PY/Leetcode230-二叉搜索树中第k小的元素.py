class Solution:
    cnt,res = 0,0
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        
        def dfs(root,k):
            if not root or self.cnt > k:
                return
            dfs(root.left,k)
            self.cnt += 1
            if self.cnt == k:
                self.res = root.val
                return 
            dfs(root.right,k)
        dfs(root,k) 

        return self.res