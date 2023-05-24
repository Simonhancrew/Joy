class Solution {
 public:
  double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
    vector<vector<int>> g(n + 1);
    // 双向边，子节点集合也有父节点
    for (const auto& e : edges) {
      g[e[0]].push_back(e[1]);
      g[e[1]].push_back(e[0]);
    }
    using PID = pair<int, double>;
    vector<PID> dis(n + 1, {INT_MAX, 0});
    dis[1] = {0, 1};
    queue<int> q;
    q.push(1);
    // 一棵树，走进一个分支就不能走另外一个分支
    // 按层数把概率均分
    while (!q.empty()) {
      auto fa = q.front();
      q.pop();
      // 大于t的节点没必要考虑
      if (dis[fa].first >= t) continue;
      for (const auto ne : g[fa]) {
        if (dis[ne].first > dis[fa].first + 1) {
          dis[ne].first = dis[fa].first + 1;
          dis[ne].second = dis[fa].second / (g[fa].size() - (fa == 1 ? 0 : 1));
          q.push(ne);
        }
      }
    }
    // 考虑如果target是叶子，小于t也无所谓，最后原地
    // 如果不是叶子几点，就要刚好等于t
    if (dis[target].first < t) {
      if (target == 1 && g[1].size() > 0 || g[target].size() > 1) {
        return 0;
      }
    }
    return dis[target].second;
  }
};
