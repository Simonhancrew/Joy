/*
    二维->一维，随机取点后二分
*/
class Solution {
 public:
  vector<vector<int>> rec;
  vector<int> s;
  Solution(vector<vector<int>> &rects) {
    rec = rects;
    s.push_back(0);
    for (auto x : rec) {
      int dx = x[2] - x[0] + 1;
      int dy = x[3] - x[1] + 1;
      s.push_back(s.back() + dx * dy);
    }
  }

  vector<int> pick() {
    int tar = rand() % s.back() + 1;
    int n = rec.size();
    int l = 1, r = n;
    while (l < r) {
      int mid = l + r >> 1;
      if (s[mid] >= tar)
        r = mid;
      else
        l = mid + 1;
    }
    auto t = rec[r - 1];
    int dx = t[2] - t[0] + 1;
    int dy = t[3] - t[1] + 1;
    return vector<int>{rand() % dx + t[0], rand() % dy + t[1]};
  }
};
