package sbgo

func hasPathSum(root *TreeNode, targetSum int) bool {
	return dfs(root, targetSum)
}

func dfs(root *TreeNode, targetSum int) bool {
	if root == nil {
		return false
	}
	if root.Left == nil && root.Right == nil {
		if root.Val == targetSum {
			return true
		}
		return false
	}
	return dfs(root.Left, targetSum-root.Val) || dfs(root.Right, targetSum-root.Val)
}
