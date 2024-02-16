#include <queue>
#include <vector>


using namespace std;

class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    if (!root) {
      return {};
    }
    queue<TreeNode *> q;
    int d = 0;
    vector<vector<int>> ans;
    q.push(root);
    vector<int> tmp;
    while (!q.empty()) {
      int n = q.size();
      for (int i = 0; i < n; i++) {
        auto *t = q.front();
        q.pop();
        tmp.push_back(t->val);
        if (t->left)
          q.push(t->left);
        if (t->right)
          q.push(t->right);
      }
      if (d & 1) {
        reverse(tmp.begin(), tmp.end());
      }
      ans.push_back(move(tmp));
      d ^= 1;
    }
    return ans;
  }
};
