class Solution:
    def isEvenOddTree(self, root: Optional[TreeNode]) -> bool:
        q = []
        q.append(root)
        st = True
        while len(q):
            n,pre,cur = len(q),0,0
            for i in range(n):
                t = q.pop(0)
                pre,cur = cur,t.val
                if t.left: q.append(t.left)
                if t.right: q.append(t.right)
                if st:
                    if cur % 2 == 0:return False
                    elif i > 0 and pre >= cur: return False
                else:
                    if cur % 2 == 1: return False
                    elif i > 0 and pre <= cur: return False
            st = not st
        return True 