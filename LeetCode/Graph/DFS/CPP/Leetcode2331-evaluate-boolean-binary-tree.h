class Solution {
 public:
  bool calcu(bool lhs, bool rhs, int val) {
    if (val == 2) {
      return lhs || rhs;
    }
    return lhs && rhs;
  }
  bool evaluateTree(TreeNode* root) {
    if (!root->left && !root->right) {
      return root->val;
    }
    return calcu(evaluateTree(root->left), evaluateTree(root->right), root->val);
  }
};
