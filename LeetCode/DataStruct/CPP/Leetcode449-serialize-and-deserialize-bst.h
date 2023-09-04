class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if (!root) {
      return "";
    }
    std::string res;
    res += to_string(root->val) + " ";
    res += serialize(root->left);
    res += serialize(root->right);
    return res;
  }

  TreeNode* dfs(const vector<int>& arr, int& idx, int lb, int rb) {
    if (idx >= arr.size() || arr[idx] > rb || arr[idx] < lb) {
      return nullptr;
    }
    auto* root = new TreeNode(arr[idx++]);
    root->left = dfs(arr, idx, lb, root->val);
    root->right = dfs(arr, idx, root->val, rb);
    return root;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    vector<int> arr;
    std::stringstream oss;
    oss << data;
    int value = 0;
    while (oss >> value) {
      arr.push_back(value);
    }
    int idx = 0;
    return dfs(arr, idx, INT_MIN, INT_MAX);
  }
};
