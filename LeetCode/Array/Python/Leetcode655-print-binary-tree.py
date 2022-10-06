class Solution:
    def printTree(self, root: Optional[TreeNode]) -> List[List[str]]:
        hei = 0

        def dfs(node, level):
            nonlocal hei
            if not node: return
            hei = max(hei, level)
            level += 1
            dfs(node.left, level)
            dfs(node.right, level)

        def dfs_fill(node, x, y):
            nonlocal ans, hei
            if not node:
                return
            ans[x][y] = str(node.val)
            if node.left:
                dfs_fill(node.left, x + 1, y - (1 << (hei - x - 1)))
            if node.right:
                dfs_fill(node.right, x + 1, y + (1 << (hei - x - 1)))

        dfs(root, 0)
        n, m = hei + 1, (1 << (hei + 1)) - 1
        ans = [[""] * m for _ in range(n)]
        dfs_fill(root, 0, (m - 1) // 2)
        return ans
