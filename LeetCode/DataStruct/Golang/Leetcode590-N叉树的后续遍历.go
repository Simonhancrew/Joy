package sbo

func postorder(root *Node) []int {
	ans := []int{}
	if root == nil {
		return ans
	}
	var dfs func(*Node)
	dfs = func(root *Node) {
		if root == nil {
			return
		}
		for _, ne := range root.Children {
			dfs(ne)
		}
		ans = append(ans, root.Val)
	}
	dfs(root)
	return ans
}
