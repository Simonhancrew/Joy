package sbgo

func deleteNode(node *ListNode) {
	*node = *node.Next
}
