package sbgo

type CBTInserter struct
{
  rec []*TreeNode
  root *TreeNode
}   


func Constructor(root *TreeNode) CBTInserter {
  rec := []*TreeNode{nil,root}
  q := []*TreeNode{root}
  for len(q) != 0 {
    t := q[0]
    q = q[1:]
    rec = append(rec,t)
    if t.Left != nil {
      q = append(q,t.Left)
    }
    if t.Right != nil {
      q = append(q,t.Right)
    }
  }
  return CBTInserter{rec,root}
}


func (this *CBTInserter) Insert(val int) int {
  node := &TreeNode{val,nil,nil}
  this.rec = append(this.rec,node)
  k := len(this.rec)
  p := k / 2;
  if p * 2 == k {
    this.rec[p].Left = node
  }else{
    this.rec[p].Right = node
  }
  return this.rec[p].Val
}


func (this *CBTInserter) Get_root() *TreeNode {
  return this.root
}

