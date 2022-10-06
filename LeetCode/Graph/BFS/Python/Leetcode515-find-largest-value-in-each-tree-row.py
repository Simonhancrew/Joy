class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        if not root: return ans
        q = deque()
        q.append(root)
        while q:
            cur, n = int(-2e39), len(q)
            for i in range(n):
                t = q.popleft()
                cur = max(cur, t.val)
                if t.left: q.append(t.left)
                if t.right: q.append(t.right)
            ans.append(cur)
        return ans
