package sbgo

func preorder(root *Node) []int {
	ans := []int{}
	var dfs func(root *Node)
	dfs = func(root *Node) {
		if root == nil {
			return
		}
		ans = append(ans, root.Val)
		for _, ne := range root.Children {
			dfs(ne)
		}
	}
	dfs(root)
	return ans
}
