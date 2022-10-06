class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        ans = []

        def dfs(root):
            if not root: return
            ans.append(root.val)
            for ne in root.children:
                dfs(ne)

        dfs(root)
        return ans
