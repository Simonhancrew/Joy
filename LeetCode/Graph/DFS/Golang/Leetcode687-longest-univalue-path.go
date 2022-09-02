package sbgo

func longestUnivaluePath(root *TreeNode) int {
  res := 0
  var dfs func(node *TreeNode) int 
  max := func(i,j int) int {
    if i < j {
      return j
    }
    return i
  }
  dfs = func(node *TreeNode) int {
    if node == nil {
      return 0
    }
    l,r := dfs(node.Left),dfs(node.Right)
    ll,rr := 0,0
    if node.Left != nil &&  node.Left.Val == node.Val {
      ll = l + 1
    }
    if node.Right != nil && node.Right.Val == node.Val {
      rr = r + 1
    }
    res = max(res,ll + rr)
    return max(ll,rr)
  }
  dfs(root)
  return res
}
