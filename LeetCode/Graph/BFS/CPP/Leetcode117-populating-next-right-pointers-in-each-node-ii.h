class Solution {
 public:
  Node* connect(Node* root) {
    if (!root) {
      return nullptr;
    }
    queue<Node*> q;
    q.push(root);
    while (q.size()) {
      int n = q.size();
      for (int i = 0; i < n; i++) {
        auto t = q.front();
        q.pop();
        if (i + 1 < n) t->next = q.front();
        if (t->left) q.push(t->left);
        if (t->right) q.push(t->right);
      }
    }
    return root;
  }
};
