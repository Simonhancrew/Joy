class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        res = []
        if not root: return res
        def dfs(root):
            if not root: return 
            for ne in root.children:
                dfs(ne)
            res.append(root.val)
        dfs(root)
        return res