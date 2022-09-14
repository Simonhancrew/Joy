class Solution {
 public:
  void dfs(TreeNode *root, vector<int> &arr) {
    if (!root) return;
    dfs(root->left, arr);
    arr.push_back(root->val);
    dfs(root->right, arr);
  }
  vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
    vector<int> arr1, arr2;
    dfs(root1, arr1), dfs(root2, arr2);
    int sum = arr1.size() + arr2.size();
    vector<int> res(sum);
    int n = arr1.size(), m = arr2.size();
    int idx = 0, l = 0, r = 0;
    while (l < n && r < m) {
      if (arr1[l] < arr2[r])
        res[idx++] = arr1[l++];
      else
        res[idx++] = arr2[r++];
    }
    while (l < n) res[idx++] = arr1[l++];
    while (r < m) res[idx++] = arr2[r++];
    return res;
  }
};