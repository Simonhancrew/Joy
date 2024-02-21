class Solution {
 public:
  unordered_map<int, int> mp;
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n = postorder.size();
    for (int i = 0; i < n; i++) {
      mp[inorder[i]] = i;
    }
    function<TreeNode*(int, int, int, int)> build = [&](int il, int ir, int pl,
                                                        int pr) -> TreeNode* {
      if (pl > pr) {
        return nullptr;
      }
      auto root_val = postorder[pr];
      auto inorder_idx = mp[root_val];
      TreeNode* root = new TreeNode(root_val);
      root->left = build(il, inorder_idx - 1, pl, pl + inorder_idx - il - 1);
      root->right = build(inorder_idx + 1, ir, pl + inorder_idx - il, pr - 1);
      return root;
    };
    return build(0, n - 1, 0, n - 1);
  }
};
