package sbgo

func findFrequentTreeSum(root *TreeNode) []int {
	mp := make(map[int]int)
	var dfs func(*TreeNode) int
	dfs = func(root *TreeNode) int {
		if root == nil {
			return 0
		}
		cur := root.Val
		if root.Left != nil {
			cur += dfs(root.Left)
		}
		if root.Right != nil {
			cur += dfs(root.Right)
		}
		mp[cur]++
		return cur
	}
	dfs(root)
	// fmt.Println(mp)
	ans, mx := []int{}, -1
	for k, v := range mp {
		if mx < v {
			ans, mx = []int{k}, v
		} else if mx == v {
			ans = append(ans, k)
		}
	}
	return ans
}
