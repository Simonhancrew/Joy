package sbgo

import (
	"strconv"
	"strings"
)

func tree2str(root *TreeNode) string {
	sb := strings.Builder{}
	var dfs func(*TreeNode)
	dfs = func(root *TreeNode) {
		if root == nil {
			return
		}
		sb.WriteString(strconv.Itoa(root.Val))
		if root.Left != nil || (root.Left == nil && root.Right != nil) {
			sb.WriteByte('(')
			dfs(root.Left)
			sb.WriteByte(')')
		}
		if root.Right != nil {
			sb.WriteByte('(')
			dfs(root.Right)
			sb.WriteByte(')')
		}
	}
	dfs(root)
	return sb.String()
}
