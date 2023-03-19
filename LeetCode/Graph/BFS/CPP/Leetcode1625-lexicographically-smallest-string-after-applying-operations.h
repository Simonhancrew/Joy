// 看作一个个的点， rotate + add， 记录没出现过的点去入队列
// 整体做一个BFS
class Solution {
 public:
  string rotate(const string& s, int b) {
    int n = s.size();
    return s.substr(n - b) + s.substr(0, n - b);
  }

  string add(string& s, int a) {
    int n = s.size();
    for (int i = 1; i < n; i += 2) {
      s[i] = '0' + (s[i] - '0' + a) % 10;
    }
    return s;
  }
  string findLexSmallestString(string s, int a, int b) {
    unordered_set<string> st;
    queue<string> q;
    string res{s};
    q.push(s);
    st.insert(s);
    while (!q.empty()) {
      auto t = q.front();
      q.pop();
      res = min(res, t);
      auto ss = rotate(t, b);
      if (!st.count(ss)) {
        st.insert(ss);
        q.push(ss);
      }
      ss = add(t, a);
      if (st.count(ss)) continue;
      st.insert(ss);
      q.push(ss);
    }
    return res;
  }
};
