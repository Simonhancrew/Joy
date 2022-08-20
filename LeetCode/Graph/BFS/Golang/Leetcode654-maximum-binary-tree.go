package sbgo

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func constructMaximumBinaryTree(nums []int) *TreeNode {
	n := len(nums)
	if n == 0 {
		return nil
	}
	var dfs func(nums []int, l, r int) *TreeNode
	dfs = func(nums []int, l, r int) *TreeNode {
		if l > r {
			return nil
		}
		if l == r {
			return &TreeNode{nums[l], nil, nil}
		}
		max_v, idx := 0, l
		for i := l; i <= r; i++ {
			if max_v < nums[i] {
				max_v = nums[i]
				idx = i
			}
		}
		node := TreeNode{max_v, nil, nil}
		node.Left = dfs(nums, l, idx-1)
		node.Right = dfs(nums, idx+1, r)
		return &node
	}
	return dfs(nums, 0, n-1)
}
