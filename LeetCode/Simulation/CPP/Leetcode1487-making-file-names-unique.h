class Solution {
 public:
  vector<string> getFolderNames(vector<string>& names) {
    int k = 0;
    vector<string> ans;
    ans.reserve(names.size());
    unordered_map<string, int> st;
    for (const auto& name : names) {
      if (!st.count(name)) {
        st[name] = 1;
        ans.push_back(name);
      } else {
        auto pa = name + "(" + to_string(st[name]) + ")";
        while (st.count(pa)) {
          st[name]++;
          pa = name + "(" + to_string(st[name]) + ")";
        }
        ans.push_back(pa);
        st[pa]++;
      }
    }
    return ans;
  }
};