class Solution {
 public:
  // 这种需要更改节点状态的，指针的引用会很好做
  // 正常节点是不需要加入的只有当前节点删除了，左右还存在是需要加入的
  // 最后判断一下根还存不存在， 存在的话加入根
  vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
    vector<TreeNode *> ans;
    unordered_set<int> st;
    for (const auto x : to_delete) st.insert(x);
    function<void(TreeNode *&)> dfs = [&](TreeNode *&node) {
      if (!node) return;
      dfs(node->left), dfs(node->right);
      if (st.count(node->val)) {
        if (node->left) ans.push_back(node->left);
        if (node->right) ans.push_back(node->right);
        node = nullptr;
      }
    };
    dfs(root);
    if (root) ans.push_back(root);
    return ans;
  }
};
