class CBTInserter:

    def __init__(self, root: TreeNode):
        self.rec = [None]
        self.root = root
        q = deque([root])
        while q:
            t = q.popleft()
            self.rec.append(t)
            if t.left: q.append(t.left)
            if t.right: q.append(t.right)
        
    def insert(self, val: int) -> int:
        node = TreeNode(val)
        self.rec.append(node)
        k = len(self.rec) - 1
        p = k // 2
        if p * 2 == k: self.rec[p].left = node
        else: self.rec[p].right = node
        return self.rec[p].val

    def get_root(self) -> TreeNode:
        return self.root
