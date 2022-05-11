package sbgo

import (
	"strconv"
	"strings"
)

type Codec struct {
}

func Constructor() Codec { return Codec{} }

// Serializes a tree to a single string.
func (this *Codec) serialize(root *TreeNode) string {
	arr := []string{}
	var dfs func(*TreeNode)
	dfs = func(node *TreeNode) {
		if node == nil {
			return
		}
		t := strconv.Itoa(node.Val)
		arr = append(arr, t)
		dfs(node.Left)
		dfs(node.Right)
	}
	dfs(root)
	return strings.Join(arr, " ")
}

// Deserializes your encoded data to tree.
func (this *Codec) deserialize(data string) *TreeNode {
	arr := strings.Split(data, " ")
	if data == "" {
		return nil
	}
	u := 0
	var dfs func(arr []string, l, r int) *TreeNode
	dfs = func(arr []string, l, r int) *TreeNode {
		if u >= len(arr) {
			return nil
		}
		t, _ := strconv.Atoi(arr[u])
		if t < l || t > r {
			return nil
		}
		t, _ = strconv.Atoi(arr[u])
		root := TreeNode{Val: t}
		u++
		root.Left = dfs(arr, l, root.Val)
		root.Right = dfs(arr, root.Val, r)
		return &root
	}
	return dfs(arr, -10010, 10010)
}
