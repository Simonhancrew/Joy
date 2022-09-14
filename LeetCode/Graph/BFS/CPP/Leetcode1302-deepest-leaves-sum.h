class Solution {
 public:
  int deepestLeavesSum(TreeNode *root) {
    int ans = 0;
    queue<TreeNode *> q;
    q.push(root);
    while (q.size()) {
      int n = q.size();
      ans = 0;
      for (int i = 0; i < n; i++) {
        auto t = q.front();
        q.pop();
        ans += t->val;
        if (t->left) q.push(t->left);
        if (t->right) q.push(t->right);
      }
    }
    return ans;
  }
};