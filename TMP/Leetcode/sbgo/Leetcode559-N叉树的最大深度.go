package sbgo

func maxDepth(root *Node) int {
	if root == nil {
		return 0
	}
	res := 0
	for _, node := range root.Children {
		res = max(res, maxDepth(node))
	}
	return res + 1
}
