class Solution {
public:
  TreeNode *pruneTree(TreeNode *root) {
    dfs(root);
    return root;
  }
  int dfs(TreeNode *&root) {
    if (!root)
      return 0;
    int cur = root->val;
    if (root->left)
      cur += dfs(root->left);
    if (root->right)
      cur += dfs(root->right);
    if (cur == 0)
      root = nullptr;
    return cur;
  }
};