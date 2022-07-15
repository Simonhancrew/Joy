package sbgo

func intersect(t1 *Node, t2 *Node) *Node {
    if t1.IsLeaf {
        if t1.Val {
            return &Node{Val:true,IsLeaf:true}
        }
        return &Node{t2.Val,t2.IsLeaf,t2.TopLeft,t2.TopRight,t2.BottomLeft,t2.BottomRight}
    }
    if t2.IsLeaf {
        return intersect(t2,t1);
    }
    o1 := intersect(t1.TopLeft,t2.TopLeft)
    o2 := intersect(t1.TopRight,t2.TopRight)
    o3 := intersect(t1.BottomLeft,t2.BottomLeft)
    o4 := intersect(t1.BottomRight,t2.BottomRight);
    if o1.IsLeaf && o2.IsLeaf && o3.IsLeaf && o4.IsLeaf && o1.Val == o2.Val && o1.Val == o3.Val && o1.Val == o4.Val {
        return &Node{Val:o1.Val,IsLeaf:true}
    }
    return &Node{false,false,o1,o2,o3,o4}
}
