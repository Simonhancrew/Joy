class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if not root: return None
        if root.val == key:
            if not root.left and not root.right:
                return None
            elif not root.left:
                return root.right
            elif not root.right:
                return root.left
            else:
                ne = root.right
                while ne.left: ne = ne.left
                ne.right = self.deleteNode(root.right,ne.val)
                ne.left = root.left
                return ne
        elif root.val > key: 
            root.left = self.deleteNode(root.left,key)
        elif root.val < key:
            root.right = self.deleteNode(root.right,key)
        return root