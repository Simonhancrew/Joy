package sbgo

func deleteNode(root *TreeNode, key int) *TreeNode {
	if root == nil {
		return nil
	}
	if root.Val == key {
		if root.Right == nil && root.Left == nil {
			return nil
		} else if root.Right == nil {
			return root.Left
		} else if root.Left == nil {
			return root.Right
		} else {
			ne := root.Right
			for ne.Left != nil {
				ne = ne.Left
			}
			ne.Right = deleteNode(root.Right, ne.Val)
			ne.Left = root.Left
			return ne
		}
	} else if root.Val > key {
		root.Left = deleteNode(root.Left, key)
	} else {
		root.Right = deleteNode(root.Right, key)
	}
	return root
}
