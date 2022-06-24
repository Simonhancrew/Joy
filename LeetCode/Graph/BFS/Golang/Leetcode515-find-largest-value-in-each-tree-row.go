package sbgo

func largestValues(root *TreeNode) []int {
	ans := []int{}
	if root == nil {
		return ans
	}
	q := []*TreeNode{root}
	for len(q) != 0 {
		n, cur := len(q), int(-3e9)
		for i := 0; i < n; i++ {
			var t = q[0]
			q = q[1:]
			cur = max(cur, t.Val)
			if t.Left != nil {
				q = append(q, t.Left)
			}
			if t.Right != nil {
				q = append(q, t.Right)
			}
		}
		ans = append(ans, cur)
	}
	return ans
}
