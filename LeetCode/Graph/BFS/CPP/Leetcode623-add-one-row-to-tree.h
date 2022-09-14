class Solution {
 public:
  void insert(TreeNode* node, int val) {
    auto lhs = new TreeNode(val), rhs = new TreeNode(val);
    auto tl = node->left, tr = node->right;
    node->left = lhs, node->right = rhs;
    lhs->left = tl, rhs->right = tr;
  }
  TreeNode* addOneRow(TreeNode* root, int val, int depth) {
    if (depth == 1) {
      auto node = new TreeNode(val);
      node->left = root;
      return node;
    }
    int level = 0;
    queue<TreeNode*> q;
    q.push(root);
    while (q.size()) {
      int n = q.size();
      level++;
      for (int i = 0; i < n; i++) {
        auto t = q.front();
        q.pop();
        if (level == depth - 1) insert(t, val);
        if (t->left) q.push(t->left);
        if (t->right) q.push(t->right);
      }
      if (level == depth - 1) break;
    }
    return root;
  }
};
