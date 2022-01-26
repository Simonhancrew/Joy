package sbgo

func pathSum(root *TreeNode, targetSum int) int {
	if root == nil {
		return 0
	}
	return pathSum(root.Left, targetSum) + pathSum(root.Right, targetSum) + dfs(root, targetSum)
}

func dfs(root *TreeNode, targetSum int) int {
	if root == nil {
		return 0
	}
	if root.Left == nil && root.Right == nil {
		if root.Val == targetSum {
			return 1
		}
		return 0
	}
	cnt := 0
	if root.Val == targetSum {
		cnt = 1
	}
	return dfs(root.Left, targetSum-root.Val) + dfs(root.Right, targetSum-root.Val) + cnt
}
