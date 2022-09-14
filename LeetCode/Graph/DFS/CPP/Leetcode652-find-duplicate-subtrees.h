// 序列化路径 + 哈希表记录，第一次出现重复加入答案
// 字符串复制整体复杂度O(n ^ 2)
class Solution {
 public:
  unordered_map<string, int> mp;
  vector<TreeNode*> ans;
  string dfs(TreeNode* node) {
    if (!node) return "";
    string cur = "";
    cur += to_string(node->val) + ",";
    cur += dfs(node->left) + ",";
    cur += dfs(node->right);
    mp[cur]++;
    if (mp[cur] == 2) {
      ans.push_back(node);
    }
    return cur;
  }

  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    dfs(root);
    return ans;
  }
};

// 三元序列化
// 记录一个子树为一个元组(root_val,left_id,right_id)
// 爆搜过程中string序列化这个元组，没出现的话就给cnt_id++，标记新的树形出现
// 当元组记录恰好为2的时候就可以记录ans
class Solution {
 public:
  int cnt = 0;
  unordered_map<string, int> mp;
  unordered_map<int, int> rec;
  vector<TreeNode*> ans;
  int dfs(TreeNode* node) {
    if (!node) return 0;
    int cur = node->val;
    int lhs = dfs(node->left);
    int rhs = dfs(node->right);
    string key = to_string(cur) + ' ' + to_string(lhs) + ' ' + to_string(rhs);
    if (mp.count(key) == 0) mp[key] = ++cnt;
    int id = mp[key];
    if (++rec[id] == 2) ans.push_back(node);
    return id;
  }
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    dfs(root);
    return ans;
  }
};
