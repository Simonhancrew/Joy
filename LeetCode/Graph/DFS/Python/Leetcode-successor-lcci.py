class Solution:
    def inorderSuccessor(self, root: TreeNode, p: TreeNode) -> TreeNode:
        stk, cur, pre = [], root, None
        while stk or cur:
            while cur:
                stk.append(cur)
                cur = cur.left
            cur = stk.pop()
            if pre == p:
                return cur
            pre = cur
            cur = cur.right
        return None
