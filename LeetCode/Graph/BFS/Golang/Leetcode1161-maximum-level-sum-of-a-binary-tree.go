package sbgo

func maxLevelSum(root *TreeNode) int {
	ans, level, layer := int(-1e9), 0, 0
	q := []*TreeNode{root}
	for len(q) != 0 {
		n, cur := len(q), 0
		layer++
		for i := 0; i < n; i++ {
			t := q[0]
			if t.Left != nil {
				q = append(q, t.Left)
			}
			if t.Right != nil {
				q = append(q, t.Right)
			}
			q = q[1:]
			cur += t.Val
		}
		if cur > ans {
			ans = cur
			level = layer
		}
	}
	return level
}
