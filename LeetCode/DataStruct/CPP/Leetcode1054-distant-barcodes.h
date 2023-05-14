#if 0
class Solution {
 public:
  using PII = pair<int, int>;
  vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    unordered_map<int, int> mp;
    for (const auto x : barcodes) mp[x]++;
    auto func = [](const PII& lhs, const PII& rhs) {
      return lhs.second < rhs.second;
    };
    priority_queue<PII, vector<PII>, decltype(func)> heap(func);
    for (const auto& [k, v] : mp) {
      heap.emplace(k, v);
    }
    int n = barcodes.size(), pre = -1;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      auto pi = heap.top();
      heap.pop();
      if (pi.first != pre) {
        ans[i] = pi.first;
        pre = ans[i];
        pi.second--;
        if (pi.second) heap.push(pi);
      } else {
        auto tt = heap.top();
        heap.pop();
        ans[i] = tt.first;
        pre = ans[i];
        tt.second--;
        if (tt.second) heap.push(tt);
        heap.push(pi);
      }
    }
    return ans;
  }
};
#else
// 插缝
class Solution {
 public:
  using PII = pair<int, int>;
  vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    unordered_map<int, int> mp;
    for (const auto x : barcodes) mp[x]++;
    int n = mp.size();
    vector<PII> heap;
    heap.reserve(n);
    for (const auto& [k, v] : mp) heap.emplace_back(k, v);
    sort(heap.begin(), heap.end(), [](const auto& lhs, const auto& rhs) {
      return lhs.second > rhs.second;
    });
    n = barcodes.size();
    vector<int> ans(n);
    int idx = 0;
    for (auto& [k, v] : heap) {
      while (v--) {
        ans[idx] = k;
        idx += 2;
        if (idx >= n) idx = 1;
      }
    }
    return ans;
  }
};
#endif
