class Solution {
 public:
  bool dfs(TreeNode *root) {
    if (!root) return true;
    if (root->left && root->left->val != root->val) return false;
    if (root->right && root->right->val != root->val) return false;
    return dfs(root->left) && dfs(root->right);
  }

  bool isUnivalTree(TreeNode *root) { return dfs(root); }
};