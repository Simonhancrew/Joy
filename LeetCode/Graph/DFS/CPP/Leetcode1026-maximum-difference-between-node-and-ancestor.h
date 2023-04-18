class Solution {
 public:
  int dfs(TreeNode* node, int mn, int mx) {
    if (!node) return -1;
    int cur = node->val;
    int res = max(abs(cur - mn), abs(mx - cur));
    mn = min(mn, cur), mx = max(mx, cur);
    res = max({res, dfs(node->left, mn, mx), dfs(node->right, mn, mx)});
    return res;
  }
  int maxAncestorDiff(TreeNode* root) {
    int val = root->val;
    return max(dfs(root->left, val, val), dfs(root->right, val, val));
  }
};
