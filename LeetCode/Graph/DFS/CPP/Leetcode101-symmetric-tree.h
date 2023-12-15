// 同时递归左右节点，lhs->left, rhs->right是一对，lhs->right, rhs->left是一对
// 一个dfs是同层次的，只要找到配对的节点就好
class Solution {
 public:
  bool dfs(TreeNode* lhs, TreeNode* rhs) {
    if (!lhs && !rhs) {
      return true;
    }
    if (!lhs || !rhs) {
      return false;
    }
    if (lhs->val != rhs->val) {
      return false;
    }
    return dfs(lhs->left, rhs->right) && dfs(lhs->right, rhs->left);
  }
  bool isSymmetric(TreeNode* root) { return dfs(root->left, root->right); }
};
