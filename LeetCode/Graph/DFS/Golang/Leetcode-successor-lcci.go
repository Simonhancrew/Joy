package sbgo

func inorderSuccessor(root *TreeNode, p *TreeNode) *TreeNode {
	stk := []*TreeNode{}
	var pre, cur *TreeNode = nil, root
	for len(stk) != 0 || cur != nil {
		for cur != nil {
			stk = append(stk, cur)
			cur = cur.Left
		}
		cur = stk[len(stk)-1]
		stk = stk[:len(stk)-1]
		if pre == p {
			return cur
		}
		pre = cur
		cur = cur.Right
	}
	return nil
}
