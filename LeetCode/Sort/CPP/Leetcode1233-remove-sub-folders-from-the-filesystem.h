class Solution {
 public:
  vector<string> removeSubfolders(vector<string> &folder) {
    ranges::sort(folder);
    vector<string> ans{move(folder[0])};
    for (int i = 1; i < folder.size(); ++i) {
      auto &cur = folder[i];
      auto &pre = ans.back();
      if (!cur.starts_with(pre) || cur[pre.size()] != '/') {
        ans.push_back(move(cur));
      }
    }
    return ans;
  }
};
