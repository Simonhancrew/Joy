class Solution {
 public:
  using PTI = pair<TreeNode*, int>;
  PTI dfs(TreeNode* root) {
    if (!root) return {nullptr, 0};
    auto lhs = dfs(root->left);
    auto rhs = dfs(root->right);
    if (rhs.second == lhs.second) {
      return {root, rhs.second + 1};
    }
    if (rhs.second > lhs.second) {
      return {rhs.first, rhs.second + 1};
    }
    return {lhs.first, lhs.second + 1};
  }
  TreeNode* lcaDeepestLeaves(TreeNode* root) { return dfs(root).first; }
};
