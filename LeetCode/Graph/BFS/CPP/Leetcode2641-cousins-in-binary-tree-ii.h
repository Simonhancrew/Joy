class Solution {
public:
  TreeNode *replaceValueInTree(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    root->val = 0;
    while (!q.empty()) {
      int n = q.size();
      int tot = 0;
      unordered_map<TreeNode *, int> mp;
      for (int i = 0; i < n; i++) {
        auto t = q.front();
        q.pop();
        if (t->left) {
          tot += t->left->val;
          mp[t->left] = t->left->val;
          if (t->right) {
            mp[t->left] += t->right->val;
          }
          q.push(t->left);
        }
        if (t->right) {
          tot += t->right->val;
          mp[t->right] = t->right->val;
          if (t->left) {
            mp[t->right] += t->left->val;
          }
          q.push(t->right);
        }
      }
      for (const auto [k, v] : mp) {
        k->val = tot - v;
      }
    }
    return root;
  }
};
