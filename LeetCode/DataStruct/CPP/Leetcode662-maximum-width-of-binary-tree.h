class Solution {
 public:
  using LL = long long;
  using PTI = pair<TreeNode*, LL>;
  int widthOfBinaryTree(TreeNode* root) {
    int mx = 0;
    queue<PTI> q;
    q.push({root, 1ll});
    while (q.size()) {
      int n = q.size();
      int l = q.front().second, r = 0;
      for (int i = 0; i < n; i++) {
        auto t = q.front();
        q.pop();
        LL base = t.second - l + 1;
        r = t.second;
        auto node = t.first;
        if (node->left) q.push({node->left, base * 2});
        if (node->right) q.push({node->right, base * 2 + 1});
      }
      mx = max(mx, r - l + 1);
    }
    return mx;
  }
};