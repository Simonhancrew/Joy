#include <queue>

using namespace std;

class Solution {
public:
  vector<vector<int>> levelOrder(Node *root) {
    if (!root) {
      return {};
    }
    vector<vector<int>> res;
    queue<Node *> q;
    q.push(root);
    while (q.size()) {
      int n = q.size();
      vector<int> cur;
      for (int i = 0; i < n; i++) {
        auto t = q.front();
        q.pop();
        cur.push_back(t->val);
        for (auto ne : t->children) {
          q.push(ne);
        }
      }
      res.push_back(std::move(cur));
    }
    return res;
  }
};
