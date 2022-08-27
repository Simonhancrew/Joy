class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        mx = 0
        q = [[root,1]]
        while q:
            n,r,l = len(q),0,q[0][1]
            for i in range(n):
                p = q[0][1] - l + 1
                r,node = q[0][1],q[0][0]
                q = q[1:]
                if node.left:
                    q.append([node.left,p * 2])
                if node.right:
                    q.append([node.right,p * 2 + 1])
            mx = max(mx,r - l + 1)
        return mx
