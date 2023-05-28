class Solution {
 public:
  using PIV = pair<int, vector<int>>;
  // 拿堆做模拟， 记录一下访问过的下标数组 
  int kthSmallest(vector<vector<int>>& mat, int k) {
    int n = mat.size(), m = mat[0].size();
    priority_queue<PIV, vector<PIV>, greater<PIV>> heap;
    vector<int> idx(n, 0);
    set<vector<int>> st;
    int sum = 0;
    for (int i = 0; i < n; i++) sum += mat[i][0];
    heap.emplace(sum, idx);
    while (--k) {
      sum = heap.top().first;
      idx = heap.top().second;
      heap.pop();
      for (int i = 0; i < n; i++) {
        int j = idx[i];
        if (j + 1 < m) {
          idx[i]++;
          if (!st.count(idx)) {
            heap.emplace(sum - mat[i][j] + mat[i][j + 1], idx);
            st.insert(idx);
          }
          idx[i]--;
        }
      }
    }
    return heap.top().first;
  }
};

