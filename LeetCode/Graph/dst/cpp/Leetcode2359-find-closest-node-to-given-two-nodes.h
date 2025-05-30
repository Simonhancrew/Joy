class Solution {
 public:
  int closestMeetingNode(vector<int> &edges, int node1, int node2) {
    int n    = edges.size();
    auto cal = [&](int x) {
      vector<int> res(n, n);
      for (int d = 0; x != -1 && res[x] == n; x = edges[x]) {
        res[x] = d++;
      }
      return res;
    };
    auto d1 = cal(node1);
    auto d2 = cal(node2);
    int ans = -1, mn = n;
    for (int i = 0; i < n; ++i) {
      auto tmp = max(d1[i], d2[i]);
      if (tmp < mn) {
        mn  = tmp;
        ans = i;
      }
    }
    return ans;
  }
};
