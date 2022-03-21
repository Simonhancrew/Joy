class Solution:
    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        st = set()
        def dfs(root):
            if not root: return False
            if root.val in st: return True  
            st.add(k - root.val)
            if dfs(root.left) or dfs(root.right):
                return True
            return False
        return dfs(root)