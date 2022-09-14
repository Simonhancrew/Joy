class Solution {
 public:
  int maxLevelSum(TreeNode *root) {
    int ans = INT_MIN, level = -1, layer = 0;
    queue<TreeNode *> q;
    q.push(root);
    while (q.size()) {
      layer++;
      int n = q.size();
      int cur = 0;
      for (int i = 0; i < n; i++) {
        auto t = q.front();
        q.pop();
        cur += t->val;
        if (t->left) q.push(t->left);
        if (t->right) q.push(t->right);
      }
      if (cur > ans) ans = cur, level = layer;
    }
    return level;
  }
};