package sbgo

func sumRootToLeaf(root *TreeNode) int {
	var dfs func(root *TreeNode, x int) int
	dfs = func(root *TreeNode, x int) int {
		if root == nil {
			return x
		}
		x = x*2 + root.Val
		if root.Left == nil && root.Right == nil {
			return x
		}
		tmp := 0
		if root.Left != nil {
			tmp += dfs(root.Left, x)
		}
		if root.Right != nil {
			tmp += dfs(root.Right, x)
		}
		return tmp
	}

	return dfs(root, 0)
}
