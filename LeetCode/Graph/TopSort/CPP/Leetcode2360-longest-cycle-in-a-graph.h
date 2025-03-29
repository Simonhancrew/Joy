class Solution {
 public:
  int longestCycle(vector<int> &edges) {
    int n = edges.size();
    vector<int> in(n, 0);
    for (int i = 0; i < n; i++) {
      if (edges[i] != -1) {
        in[edges[i]]++;
      }
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
      if (in[i] == 0)
        q.push(i);
    }
    while (!q.empty()) {
      auto t = q.front();
      q.pop();
      int ne = edges[t];
      if (ne == -1) {
        continue;
      }
      in[ne]--;
      if (in[ne] == 0) {
        q.push(ne);
      }
    }
    bool circle = false;
    for (int i = 0; i < n; i++) {
      if (in[i] != 0) {
        circle = true;
        break;
      }
    }
    if (!circle) {
      return -1;
    }
    unordered_set<int> st;
    auto dfs = [&](this auto &&dfs, int x) {
      if (st.count(x)) {
        return 0;
      }
      st.insert(x);
      auto ne = edges[x];
      return 1 + dfs(ne);
    };
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (in[i] == 0 || st.count(i)) {
        continue;
      }
      ans = max(ans, dfs(i));
    }
    return ans;
  }
};
