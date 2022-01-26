package sbgo

func isEvenOddTree(root *TreeNode) bool {
	q, st := []*TreeNode{}, true
	q = append(q, root)
	for len(q) > 0 {
		n, pre, cur := len(q), 0, 0
		for i := 0; i < n; i++ {
			t := q[0]
			pre, cur = cur, t.Val
			q = q[1:]
			if t.Left != nil {
				q = append(q, t.Left)
			}
			if t.Right != nil {
				q = append(q, t.Right)
			}
			if st {
				if cur%2 == 0 {
					return false
				}
				if i > 0 && pre >= cur {
					return false
				}
			} else {
				if cur%2 == 1 {
					return false
				}
				if i > 0 && pre <= cur {
					return false
				}
			}
		}
		st = !st
	}
	return true
}
