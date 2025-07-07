class Solution {
 public:
  int maxEvents(vector<vector<int>> &events) {
    int mx = 0;
    for (const auto &x : events) {
      mx = max(mx, x[1]);
    }
    vector<vector<int>> mp(mx + 1);
    for (const auto &x : events) {
      mp[x[0]].push_back(x[1]);
    }
    int ans = 0;
    priority_queue<int, vector<int>, greater<>> heap;
    for (int i = 1; i < mp.size(); ++i) {
      while (heap.size() && heap.top() < i) {
        heap.pop();
      }
      for (const auto x : mp[i]) {
        heap.push(x);
      }
      if (!heap.empty()) {
        ++ans;
        heap.pop();
      }
    }
    return ans;
  }
};
