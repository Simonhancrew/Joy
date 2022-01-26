package sbgo

func kthSmallest(root *TreeNode, k int) int {
	res, cnt := 0, 0
	var dfs func(*TreeNode, int)
	dfs = func(root *TreeNode, k int) {
		if root == nil || cnt > k {
			return
		}
		dfs(root.Left, k)
		cnt++
		if cnt == k {
			res = root.Val
			return
		}
		dfs(root.Right, k)
	}
	dfs(root, k)
	return res
}
