package sbgo

func levelOrder(root *Node) [][]int {
	res, q := [][]int{}, []*Node{root}
	if root == nil {
		return res
	}
	for len(q) != 0 {
		n, cur := len(q), []int{}
		for i := 0; i < n; i++ {
			t := q[0]
			q = q[1:]
			cur = append(cur, t.Val)
			for _, ne := range t.Children {
				q = append(q, ne)
			}
		}
		res = append(res, cur)
	}
	return res
}
