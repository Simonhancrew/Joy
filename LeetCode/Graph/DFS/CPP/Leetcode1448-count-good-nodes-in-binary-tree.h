class Solution {
 public:
  int dfs(TreeNode *node, int mx) {
    if (!node) {
      return 0;
    }
    int ans = 0;
    if (mx <= node->val) {
      mx = node->val;
      ans += 1;
    }
    ans += dfs(node->left, mx);
    ans += dfs(node->right, mx);
    return ans;
  }

  int goodNodes(TreeNode *root) { return dfs(root, root->val); }
};
