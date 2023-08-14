class Solution {
 public:
  TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
    if (!root1 && !root2) {
      return nullptr;
    }
    if (!root1) {
      root1 = root2;
      root2 = nullptr;
    }
    root1->val += root2 ? root2->val : 0;
    root1->left = mergeTrees(root1->left, root2 ? root2->left : nullptr);
    root1->right = mergeTrees(root1->right, root2 ? root2->right : nullptr);
    return root1;
  }
};
