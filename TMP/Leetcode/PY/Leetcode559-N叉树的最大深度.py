class Solution:
    def maxDepth(self, root: 'Node') -> int:
        if not root: return 0
        res = 0
        for node in root.children:
            res = max(res,self.maxDepth(node))
        return res + 1