class Solution {
public:
  using LL = long long;
  long long kthLargestLevelSum(TreeNode *root, int k) {
    if (!root) {
      return -1;
    }
    priority_queue<LL, vector<LL>, greater<>> heap;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      auto n = q.size();
      LL acc = 0;
      for (int i = 0; i < n; i++) {
        auto *t = q.front();
        q.pop();
        acc += t->val;
        if (t->left)
          q.push(t->left);
        if (t->right)
          q.push(t->right);
      }
      if (heap.size() >= k && heap.top() < acc) {
        heap.pop();
      }
      if (heap.size() < k) {
        heap.push(acc);
      }
    }
    return heap.size() == k ? heap.top() : -1;
  }
};
