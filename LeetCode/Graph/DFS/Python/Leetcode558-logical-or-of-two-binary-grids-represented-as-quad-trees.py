class Solution:
    def intersect(self, t1, t2) -> 'Node':
        if t1.isLeaf:
            if t1.val:
                return Node(True, True)
            return Node(t2.val, t2.isLeaf, t2.topLeft, t2.topRight,
                        t2.bottomLeft, t2.bottomRight)
        if t2.isLeaf:
            return self.intersect(t2, t1)
        o1 = self.intersect(t1.topLeft, t2.topLeft)
        o2 = self.intersect(t1.topRight, t2.topRight)
        o3 = self.intersect(t1.bottomLeft, t2.bottomLeft)
        o4 = self.intersect(t1.bottomRight, t2.bottomRight)
        if o1.isLeaf and o2.isLeaf and o3.isLeaf and o4.isLeaf and o1.val == o2.val == o3.val == o4.val:
            return Node(o1.val, True)
        return Node(False, False, o1, o2, o3, o4)
