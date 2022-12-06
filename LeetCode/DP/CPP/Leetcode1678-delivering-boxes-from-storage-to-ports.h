class Solution {
 public:
  vector<int> s;
  int cost(int l, int r) {
    if (r >= s.size()) r = s.size() - 1;
    if (s[l] != s[min(l + 1, int(s.size()) - 1)]) return s[r] - s[l];
    return s[r] - s[l] + 1;
  }
  int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
    int n = boxes.size();
    s.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      s[i] = s[i - 1];
      if (i == 1 || boxes[i - 1][0] != boxes[i - 2][0]) s[i]++;
    }

    vector<int> f(n + 1);
    deque<int> q;
    q.push_back(0);
    int w = 0;
    for (int i = 1, j = 1; i <= n; i++) {
      w += boxes[i - 1][1];
      while (w > maxWeight || i - j + 1 > maxBoxes) {
        w -= boxes[j - 1][1];
        j++;
      }
      while (q.size() && q.front() < j - 1) q.pop_front();
      auto t = q.front();
      f[i] = f[t] + cost(t, i) + 1;
      while (q.size() && f[q.back()] >= f[i] + cost(i, i + 1) - cost(q.back(), i + 1)) {
        q.pop_back();
      }
      q.push_back(i);
    }
    return f[n];
  }
};