class Solution {
 public:
  unordered_set<TreeNode*> mp;
  bool dfs(TreeNode* root, TreeNode* tar) {
    if (root == nullptr) {
      return 0;
    }
    if (root == tar) {
      mp.insert(tar);
      return 1;
    }
    auto res = dfs(root->left, tar);
    if (res > 0) {
      mp.insert(root);
      return 1;
    }
    res = dfs(root->right, tar);
    if (res > 0) {
      mp.insert(root);
      return 1;
    }
    return 0;
  }
  TreeNode* final{};
  bool dfs_r(TreeNode* root, TreeNode* tar) {
    if (root == nullptr) {
      return 0;
    }
    if (root == tar) {
      if (mp.count(tar) && final == nullptr) {
        final = tar;
      }
      return 1;
    }
    auto res = dfs_r(root->left, tar);
    if (res) {
      if (mp.count(root) && final == nullptr) {
        final = root;
      }
      return 1;
    }
    res = dfs_r(root->right, tar);
    if (res > 0) {
      if (mp.count(root) && final == nullptr) {
        final = root;
      }
      return 1;
    }
    return 0;
  }

  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    dfs(root, p);
    dfs_r(root, q);
    return final;
  }
};
