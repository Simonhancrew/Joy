class Solution:
    def findFrequentTreeSum(self, root: TreeNode) -> List[int]:
        mp = defaultdict(int)
        def dfs(root):
            if not root: return 0
            cur = root.val
            if root.left: 
                cur += dfs(root.left)
            if root.right:
                cur += dfs(root.right)
            mp[cur] += 1
            return cur
        dfs(root)
        mx,ans = -1,[]
        for k,v in mp.items():
            if mx < v:
                mx,ans = v,[k]
            elif mx == v:
                ans.append(k)
        return ans