class Solution {
 public:
  vector<string> subdomainVisits(vector<string> &cpdomains) {
    unordered_map<string, int> mp;
    vector<string> ans;
    for (auto &cp : cpdomains) {
      int sp = cp.find(' '), num = stoi(cp.substr(0, sp));
      string pa = cp.substr(sp + 1);
      mp[pa] += num;
      int st = 0;
      while (pa.find('.', st) != string::npos) {
        auto t = pa.find('.', st);
        auto s = pa.substr(t + 1);
        mp[s] += num;
        st = t + 1;
      }
    }
    for (auto &[k, v] : mp) {
      ans.push_back(to_string(v) + " " + k);
    }
    return ans;
  }
};