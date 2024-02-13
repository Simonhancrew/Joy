/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  unordered_map<TreeNode *, tuple<int, int, int>> mp;
  void dfs(TreeNode *node, int r, int c) {
    if (!node) {
      return;
    }
    mp[node] = {r, c, node->val};
    dfs(node->left, r + 1, c - 1);
    dfs(node->right, r + 1, c + 1);
  }

  vector<vector<int>> verticalTraversal(TreeNode *root) {
    dfs(root, 0, 0);
    vector<tuple<int, int, int>> res;
    res.reserve(mp.size());
    for (auto &x : mp) {
      res.push_back(move(x.second));
    }
    ranges::sort(res, [](auto &lhs, auto &rhs) {
      if (get<1>(lhs) != get<1>(rhs))
        return get<1>(lhs) < get<1>(rhs);
      if (get<0>(lhs) != get<0>(rhs))
        return get<0>(lhs) < get<0>(rhs);
      return get<2>(lhs) < get<2>(rhs);
    });
    vector<vector<int>> ans;
    int n = res.size();
    for (int i = 0; i < n; i++) {
      int j = i;
      vector<int> tmp;
      while (j < n && get<1>(res[j]) == get<1>(res[i])) {
        tmp.push_back(get<2>(res[j]));
        ++j;
      }
      ans.push_back(move(tmp));
      i = j - 1;
    }
    return ans;
  }
};
