class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:   
        arr1,arr2 = [],[]
        
        def dfs(node,arr):
            if not node: return 
            dfs(node.left,arr)
            arr.append(node.val)
            dfs(node.right,arr)

        dfs(root1,arr1)
        dfs(root2,arr2)
        
        n,m = len(arr1),len(arr2)
        idx,l,r,tot = 0,0,0,n + m
        res = [0] * tot

        while l < n and r < m:
            if arr1[l] < arr2[r]:
                res[idx] = arr1[l]
                l += 1
            else:
                res[idx] = arr2[r]
                r += 1
            idx += 1
        
        while l < n:
            res[idx] = arr1[l]
            l,idx = l + 1,idx + 1
        while r < m:
            res[idx] = arr2[r]
            r,idx = r + 1,idx + 1
        
        return res