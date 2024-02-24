
#include <functional>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> closestNodes(TreeNode *root, vector<int> &queries) {
    vector<int> rec;
    function<void(TreeNode *)> dfs = [&](TreeNode *node) {
      if (!node) {
        return;
      }
      dfs(node->left);
      rec.push_back(node->val);
      dfs(node->right);
    };
    dfs(root);
    auto search = [&](int val) -> vector<int> {
      int l = -1, r = rec.size();
      while (l + 1 < r) {
        int mid = l + r >> 1;
        if (rec[mid] <= val)
          l = mid;
        else
          r = mid;
      }
      int lhs = l == -1 ? -1 : rec[l];
      l = l == -1 ? -1 : l - 1, r = rec.size();
      while (l + 1 < r) {
        int mid = l + r >> 1;
        if (rec[mid] >= val)
          r = mid;
        else
          l = mid;
      }
      int rhs = r == rec.size() ? -1 : rec[r];
      return {lhs, rhs};
    };
    int n = queries.size();
    vector<vector<int>> res;
    res.reserve(n);
    for (const auto x : queries) {
      res.push_back(search(x));
    }
    return res;
  }
};
