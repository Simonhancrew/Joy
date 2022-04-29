package sbgo

func construct(grid [][]int) *Node {
	n := len(grid)
	rec := make([][]int, n+1)
	for i := 0; i <= n; i++ {
		rec[i] = make([]int, n+1)
	}
	for i := 1; i <= n; i++ {
		for j := 1; j <= n; j++ {
			rec[i][j] = rec[i-1][j] + rec[i][j-1] - rec[i-1][j-1] + grid[i-1][j-1]
		}
	}
	var dfs func(x1, y1, x2, y2 int) *Node
	dfs = func(x1, y1, x2, y2 int) *Node {
		n := x2 - x1 + 1
		tot := rec[x2][y2] - rec[x2][y1-1] - rec[x1-1][y2] + rec[x1-1][y1-1]
		if tot == 0 || tot == n*n {
			res := Node{}
			res.IsLeaf = true
			if tot == 0 {
				res.Val = false
			} else {
				res.Val = true
			}
			return &res
		}
		node := Node{Val: false, IsLeaf: false}
		m := n / 2
		node.TopLeft = dfs(x1, y1, x1+m-1, y1+m-1)
		node.TopRight = dfs(x1, y1+m, x1+m-1, y2)
		node.BottomLeft = dfs(x1+m, y1, x2, y1+m-1)
		node.BottomRight = dfs(x1+m, y1+m, x2, y2)
		return &node
	}
	return dfs(1, 1, n, n)
}
