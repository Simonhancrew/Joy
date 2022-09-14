class Solution {
 public:
  string t;
  vector<string> uncommonFromSentences(string s1, string s2) {
    stringstream ss(s1);
    unordered_map<string, int> st;
    while (ss >> t) {
      st[t]++;
    }
    ss.str("");
    ss.clear();
    ss << s2;
    while (ss >> t) {
      st[t]++;
    }
    vector<string> ans;
    for (auto &[k, v] : st) {
      cout << k << ":" << v << endl;
      if (v == 1) ans.push_back(k);
    }
    return ans;
  }
};