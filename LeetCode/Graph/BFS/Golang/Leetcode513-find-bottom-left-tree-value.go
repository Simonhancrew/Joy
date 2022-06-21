package sbgo

func findBottomLeftValue(root *TreeNode) int {
	val, hei := 0, 0
	var dfs func(node *TreeNode, h int)
	dfs = func(node *TreeNode, h int) {
		if node == nil {
			return
		}
		h++
		dfs(node.Left, h)
		dfs(node.Right, h)
		if h > hei {
			hei = h
			val = node.Val
		}
	}
	dfs(root, 0)
	return val
}
