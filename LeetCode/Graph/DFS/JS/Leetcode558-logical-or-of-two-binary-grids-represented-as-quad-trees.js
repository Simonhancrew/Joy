var intersect = function(t1, t2) {
    if(t1.isLeaf) {
        if(t1.val) {
            return new Node(true,true);
        }
        return new Node(t2.val,t2.isLeaf,t2.topLeft,t2.topRight,t2.bottomLeft,t2.bottomRight);
    }
    if(t2.isLeaf) {
        return intersect(t2,t1);
    }
    let o1 = new intersect(t1.topLeft,t2.topLeft);
    let o2 = new intersect(t1.topRight,t2.topRight);
    let o3 = new intersect(t1.bottomLeft,t2.bottomLeft);
    let o4 = new intersect(t1.bottomRight,t2.bottomRight);
    if(o1.isLeaf && o2.isLeaf && o3.isLeaf && o4.isLeaf && o1.val == o2.val && o1.val == o3.val && o1.val == o4.val) {
        return new Node(o1.val,true);
    }
    return new Node(false,false,o1,o2,o3,o4);
};
