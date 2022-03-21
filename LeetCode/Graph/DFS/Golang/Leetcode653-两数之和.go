package sbgo

type void struct{}

var mem void

func findTarget(root *TreeNode, k int) bool {
	st := make(map[int]void)
	var dfs func(*TreeNode) bool
	dfs = func(root *TreeNode) bool {
		if root == nil {
			return false
		}
		if _, ok := st[root.Val]; ok {
			return true
		}
		st[k-root.Val] = mem
		if dfs(root.Left) || dfs(root.Right) {
			return true
		}
		return false
	}
	return dfs(root)
}
