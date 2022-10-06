class Solution:
    def findDuplicateSubtrees(
            self, root: Optional[TreeNode]) -> List[Optional[TreeNode]]:
        ans, cnt, rec, mp = [], 0, defaultdict(int), defaultdict(int)

        def dfs(node):
            nonlocal cnt
            if not node: return 0
            cur = node.val
            lhs = dfs(node.left)
            rhs = dfs(node.right)
            key = str(cur) + ' ' + str(lhs) + ' ' + str(rhs)
            if mp[key] == 0:
                cnt += 1
                mp[key] = cnt
            id = mp[key]
            rec[id] += 1
            if rec[id] == 2: ans.append(node)
            return id

        dfs(root)
        return ans
