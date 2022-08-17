class Solution:
    def addOneRow(self, root: Optional[TreeNode], val: int, depth: int) -> Optional[TreeNode]:
        if depth == 1:
            node = TreeNode(val)
            node.left = root
            return node
        
        q,level = deque([root]),0
        
        def insert(node,value):
            lhs,rhs = TreeNode(value),TreeNode(value)
            tl,tr = node.left,node.right
            node.left,node.right = lhs,rhs
            lhs.left,rhs.right = tl,tr
    
        while q:
            n = len(q)
            level += 1
            if level == depth: break
            for i in range(n):
                t = q.popleft()
                if level == depth - 1:
                    insert(t,val)
                if t.left: q.append(t.left)
                if t.right: q.append(t.right)
        return root