package sbgo

type pair struct {
	node  *TreeNode
	level int
}

func max(i, j int) int {
	if i < j {
		return j
	}
	return i
}
func widthOfBinaryTree(root *TreeNode) int {
	q := []pair{pair{root, 1}}
	mx := 0
	for len(q) != 0 {
		n := len(q)
		l, r := q[0].level, 0
		for i := 0; i < n; i++ {
			t, p := q[0].node, q[0].level-l+1
			r = q[0].level
			q = q[1:]
			if t.Left != nil {
				q = append(q, pair{t.Left, p * 2})
			}
			if t.Right != nil {
				q = append(q, pair{t.Right, p*2 + 1})
			}
		}
		mx = max(mx, r-l+1)
	}
	return mx
}
