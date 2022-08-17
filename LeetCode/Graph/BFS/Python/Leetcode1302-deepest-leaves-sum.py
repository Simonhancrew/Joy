class Solution:
    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:
        q,ans = deque([root]),0
        while q:
            n = len(q)
            ans = 0
            for i in range(n):
                t = q.popleft()
                ans += t.val
                if t.left: q.append(t.left)
                if t.right: q.append(t.right)
        return ans