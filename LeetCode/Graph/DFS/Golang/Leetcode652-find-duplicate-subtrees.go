package sbgo

func findDuplicateSubtrees(root *TreeNode) []*TreeNode {
  ans,rec,mp := []*TreeNode{},make(map[int]int),make(map[string]int)
  cnt := 0
  var dfs func(*TreeNode) int 
  dfs = func(node *TreeNode) int {
    if node == nil {
      return 0
    }
    cur := node.Val
    lhs := dfs(node.Left)
    rhs := dfs(node.Right)
    key := strconv.Itoa(cur) + " " + strconv.Itoa(lhs) + " " + strconv.Itoa(rhs)
    if _,ok := mp[key];!ok {
      cnt++
      mp[key] = cnt
    }
    id := mp[key]
    rec[id]++
    if rec[id] == 2 {
      ans = append(ans,node)
    }
    return id
  } 
  dfs(root)
  return ans
}
