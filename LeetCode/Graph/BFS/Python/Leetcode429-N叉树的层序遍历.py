class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if not root: return []
        res,q = [],deque()
        q.append(root)
        while q:
            n,cur = len(q),[]
            for i in range(n):
                t = q.popleft()            
                cur.append(t.val)
                for ne in t.children:
                    q.append(ne)
            res.append(cur)
        return res