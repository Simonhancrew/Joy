class Solution {
 public:
  int dfs(TreeNode* node) {
    if (!node) {
      return 0;
    }
    int res = node->val;
    res += dfs(node->left);
    res += dfs(node->right);
    return res;
  }

  bool checkTree(TreeNode* root) {
    if (!root) {
      return true;
    }
    int root_val = root->val;
    int leaf_val = 0;
    leaf_val += dfs(root->left);
    leaf_val += dfs(root->right);
    return root_val == leaf_val;
  }
};
