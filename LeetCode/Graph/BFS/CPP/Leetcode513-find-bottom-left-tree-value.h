class Solution {
 public:
  int findBottomLeftValue(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    int res = -1;
    while (q.size()) {
      int n = q.size();
      res = q.front()->val;
      for (int i = 0; i < n; i++) {
        auto t = q.front();
        q.pop();
        if (t->left) q.push(t->left);
        if (t->right) q.push(t->right);
      }
    }
    return res;
  }
};