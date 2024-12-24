class Solution {
 public:
  using PII = pair<int, int>;
  int eatenApples(vector<int> &apples, vector<int> &days) {
    priority_queue<PII, vector<PII>, greater<>> heap;
    int res = 0, n = apples.size();
    for (int i = 0; i < n; i++) {
      if (apples[i] > 0) {
        heap.push({i + days[i], apples[i]});
      }
      while (!heap.empty() && heap.top().first <= i) {
        heap.pop();
      }
      if (!heap.empty()) {
        auto [day, cnt] = heap.top();
        heap.pop();
        res++;
        if (cnt > 1) {
          heap.emplace(day, cnt - 1);
        }
      }
    }
    int i = n;
    while (!heap.empty()) {
      while (!heap.empty() && (heap.top().first <= i)) {
        heap.pop();
      }
      if (!heap.empty()) {
        auto [day, cnt] = heap.top();
        heap.pop();
        res++;
        if (cnt > 1) {
          heap.emplace(day, cnt - 1);
        }
      }
      i++;
    }
    return res;
  }
};
