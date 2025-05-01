class Solution {
 public:
  int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills,
                    int strength) {
    ranges::sort(workers);
    ranges::sort(tasks);
    int n = tasks.size(), m = workers.size();
    auto check = [&](int k) {
      int i = 0, p = pills;
      deque<int> q;
      for (int j = m - k; j < m; j++) {
        int w = workers[j];
        while (i < k && w + strength >= tasks[i]) {
          q.push_back(tasks[i]);
          i++;
        }
        if (q.empty()) {
          return false;
        }
        if (w >= q.front()) {
          q.pop_front();
          continue;
        }
        if (p == 0) {
          return false;
        }
        --p;
        q.pop_back();
      }
      return true;
    };
    int l = -1, r = min(m, n) + 1;
    while (l + 1 < r) {
      int mid = l + r >> 1;
      if (check(mid))
        l = mid;
      else
        r = mid;
    }
    return l;
  }
};
