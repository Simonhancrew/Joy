#include <unordered_map>

using namespace std;

// 判断回文，看出现奇数次的字符是否超过1个

class Solution {
 public:
  unordered_map<int, int> mp;
  int ans{};

  bool check(unordered_map<int, int>& mp) {
    int cnt = 0;
    for (const auto& [k, v] : mp) {
      if (v & 1) cnt++;
      if (cnt > 1) return false;
    }
    return cnt <= 1;
  }

  void dfs(TreeNode* node) {
    if (!node) {
      return;
    }
    if (node->left) {
      mp[node->left->val]++;
      dfs(node->left);
      mp[node->left->val]--;
    }
    if (node->right) {
      mp[node->right->val]++;
      dfs(node->right);
      mp[node->right->val]--;
    }
    if (!node->left && !node->right) {
      if (check(mp)) ++ans;
    }
  }
  int pseudoPalindromicPaths(TreeNode* root) {
    if (!root) return 0;
    mp[root->val]++;
    dfs(root);
    return ans;
  }
};
