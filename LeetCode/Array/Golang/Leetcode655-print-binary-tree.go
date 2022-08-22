package sbgo

import "strconv"

func printTree(root *TreeNode) [][]string {
	hei := 0
	var dfs func(node *TreeNode, level int)
	dfs = func(node *TreeNode, level int) {
		if node == nil {
			return
		}
		if level > hei {
			hei = level
		}
		dfs(node.Left, level+1)
		dfs(node.Right, level+1)
	}
	dfs(root, 0)
	n, m := hei+1, (1<<(hei+1))-1
	ans := make([][]string, n)
	for i := 0; i < n; i++ {
		ans[i] = make([]string, m)
	}
	var dfs_fill func(node *TreeNode, x, y int)
	dfs_fill = func(node *TreeNode, x, y int) {
		if node == nil {
			return
		}
		ans[x][y] = strconv.Itoa(node.Val)
		if node.Left != nil {
			dfs_fill(node.Left, x+1, y-(1<<(hei-x-1)))
		}
		if node.Right != nil {
			dfs_fill(node.Right, x+1, y+(1<<(hei-x-1)))
		}
	}
	dfs_fill(root, 0, (m-1)/2)
	return ans
}
