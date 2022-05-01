package sbgo

/*
	[]int值传递，可以修改，但是有扩容的话还是老实传
	指针吧。因为扩容的时候修改了内部的指向[n]int数组的指针
	值传递修改时没法一致的
*/
func getAllElements(root1 *TreeNode, root2 *TreeNode) []int {
	arr1, arr2 := []int{}, []int{}
	var dfs func(node *TreeNode, arr *[]int)
	dfs = func(node *TreeNode, arr *[]int) {
		if node == nil {
			return
		}
		dfs(node.Left, arr)
		*arr = append(*arr, node.Val)
		dfs(node.Right, arr)
	}

	dfs(root1, &arr1)
	dfs(root2, &arr2)

	n, m, l, r, idx := len(arr1), len(arr2), 0, 0, 0
	res := make([]int, n+m)
	for l < n && r < m {
		if arr1[l] < arr2[r] {
			res[idx] = arr1[l]
			l++
		} else {
			res[idx] = arr2[r]
			r++
		}
		idx++
	}
	for l < n {
		res[idx] = arr1[l]
		idx, l = idx+1, l+1
	}
	for r < m {
		res[idx] = arr2[r]
		idx, r = idx+1, r+1
	}
	return res
}
