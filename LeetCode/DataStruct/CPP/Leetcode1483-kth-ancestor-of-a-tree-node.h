class TreeAncestor {
 public:
  unordered_map<int, vector<int>> tr;
  vector<int> depth;
  vector<vector<int>> fa;
  TreeAncestor(int n, vector<int>& parent) {
    int tot = parent.size();
    for (int i = 0; i < tot; i++) {
      auto fa = parent[i];
      if (fa == -1) continue;
      tr[fa].push_back(i);
    }
    bfs(n);
  }

  void bfs(int n) {
    depth.resize(n, 5e4 + 10);
    depth[0] = 0;
    fa.resize(n, vector<int>(17));
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
      auto t = q.front();
      q.pop();
      for (const auto ne : tr[t]) {
        depth[ne] = depth[t] + 1;
        q.push(ne);
        fa[ne][0] = t;
        for (int i = 1; i < 17; i++) {
          fa[ne][i] = fa[fa[ne][i - 1]][i - 1];
        }
      }
    }
  }

  int getKthAncestor(int node, int k) {
    if (depth[node] < k) {
      return -1;
    }
    int acc = 0;
    while (k) {
      if (k & 1) node = fa[node][acc];
      acc += 1;
      k >>= 1;
    }
    return node;
  }
};
