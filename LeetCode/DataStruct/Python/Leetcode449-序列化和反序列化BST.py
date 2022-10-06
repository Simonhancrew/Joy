class Codec:
    def serialize(self, root: TreeNode) -> str:
        """Encodes a tree to a single string.
        """
        res = ''
        if not root: return res
        res += str(root.val) + ' '
        res += self.serialize(root.left)
        res += self.serialize(root.right)
        return res

    def deserialize(self, data: str) -> TreeNode:
        """Decodes your encoded data to tree.
        """
        arr = list(map(int, data.split()))
        u = 0

        def dfs(arr, l, r):
            nonlocal u
            if u == len(arr) or arr[u] < l or arr[u] > r:
                return None
            root = TreeNode(arr[u])
            u += 1
            root.left = dfs(arr, l, root.val)
            root.right = dfs(arr, root.val, r)
            return root

        return dfs(arr, -10010, 10010)
