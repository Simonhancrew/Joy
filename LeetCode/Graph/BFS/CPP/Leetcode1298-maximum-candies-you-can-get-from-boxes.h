class Solution {
 public:
  int maxCandies(vector<int> &status, vector<int> &candies,
                 vector<vector<int>> &keys, vector<vector<int>> &containedBoxes,
                 vector<int> &initialBoxes) {
    unordered_set<int> box(status.size());
    unordered_set<int> key(status.size());
    queue<int> q;
    for (const auto x : initialBoxes) {
      if (status[x] == 1) {
        q.push(x);
      } else {
        box.insert(x);
      }
    }
    int ans = 0;
    while (!q.empty()) {
      auto t = q.front();
      q.pop();
      ans += candies[t];
      cout << t << ' ' << candies[t] << " " << ans << '\n';
      for (const auto k : keys[t]) {
        if (box.count(k)) {
          box.erase(k);
          q.push(k);
        } else {
          key.insert(k);
        }
      }
      for (const auto b : containedBoxes[t]) {
        if (status[b] == 1) {
          q.push(b);
          continue;
        }
        if (key.count(b)) {
          q.push(b);
          key.erase(b);
        } else {
          box.insert(b);
        }
      }
    }
    return ans;
  }
};
