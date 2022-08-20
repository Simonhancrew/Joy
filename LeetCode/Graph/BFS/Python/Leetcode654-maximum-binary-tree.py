class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> Optional[TreeNode]:
        n = len(nums)
        if not n: return None
        def dfs(nums,l,r):
            if l == r:
                return TreeNode(nums[l])
            if l > r:
                return None
            max_v,idx = 0,l
            for i in range(l,r + 1):
                if max_v < nums[i]: 
                    max_v = nums[i]
                    idx = i
            tar = TreeNode(max_v)
            tar.left = dfs(nums,l,idx - 1)
            tar.right = dfs(nums,idx + 1,r)
            return tar
        return dfs(nums,0,n - 1)