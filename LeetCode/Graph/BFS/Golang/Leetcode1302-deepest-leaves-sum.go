package sbgo

func deepestLeavesSum(root *TreeNode) int {
	ans, q := 0, []*TreeNode{root}
	for len(q) != 0 {
		n := len(q)
		ans = 0
		for i := 0; i < n; i++ {
			t := q[0]
			ans += t.Val
			q = q[1:]
			if t.Left != nil {
				q = append(q, t.Left)
			}
			if t.Right != nil {
				q = append(q, t.Right)
			}
		}
	}
	return ans
}
