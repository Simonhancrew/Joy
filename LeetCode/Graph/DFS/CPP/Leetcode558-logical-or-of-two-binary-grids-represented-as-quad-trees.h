/*
  如果是子节点的话，直接或得到结果就行
  如果不是子节点，就递归的做四个区域，合并结果。
*/

class Solution {
 public:
  Node* intersect(Node* t1, Node* t2) {
    if (t1->isLeaf) {
      if (t1->val) {
        return new Node(t1->val, true);
      }
      return new Node(t2->val, t2->isLeaf, t2->topLeft, t2->topRight,
                      t2->bottomLeft, t2->bottomRight);
    }
    if (t2->isLeaf) {
      return intersect(t2, t1);
    }
    auto o1 = intersect(t1->topLeft, t2->topLeft);
    auto o2 = intersect(t1->topRight, t2->topRight);
    auto o3 = intersect(t1->bottomLeft, t2->bottomLeft);
    auto o4 = intersect(t1->bottomRight, t2->bottomRight);
    if (o1->isLeaf && o2->isLeaf && o3->isLeaf && o4->isLeaf &&
        o1->val == o2->val && o1->val == o3->val && o1->val == o4->val) {
      return new Node(o1->val, true);
    }
    return new Node(false, false, o1, o2, o3, o4);
  }
};
