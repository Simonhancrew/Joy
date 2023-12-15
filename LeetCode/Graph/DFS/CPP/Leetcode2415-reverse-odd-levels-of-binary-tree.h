// 反转->对称二叉树，交换值
// 同时递归左右节点，lhs->left, rhs->right是一对，lhs->right, rhs->left是一对
// 一个dfs是同层次的，只要找到配对的节点就好
class Solution {
 public:
  void dfs(TreeNode* lhs, TreeNode* rhs, bool swap_val) {
    if (!lhs) {
      return;
    }
    if (swap_val) swap(lhs->val, rhs->val);
    dfs(lhs->left, rhs->right, !swap_val);
    dfs(lhs->right, rhs->left, !swap_val);
  }
  TreeNode* reverseOddLevels(TreeNode* root) {
    dfs(root->left, root->right, true);
    return root;
  }
};