class Solution {
 public:
  void dfs(TreeNode*& node, int sum, int limit) {
    sum += node->val;
    if (!node->left && !node->right) {
      if (sum < limit) {
        node = nullptr;
      }
    } else {
      if (node->left) dfs(node->left, sum, limit);
      if (node->right) dfs(node->right, sum, limit);
      if (!node->right && !node->left) {
        node = nullptr;
      }
    }
  }
  TreeNode* sufficientSubset(TreeNode* root, int limit) {
    dfs(root, 0, limit);
    return root;
  }
};
