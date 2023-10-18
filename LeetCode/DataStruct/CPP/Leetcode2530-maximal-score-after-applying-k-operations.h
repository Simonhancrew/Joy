class Solution {
 public:
  using LL = long long;
  long long maxKelements(vector<int>& nums, int k) {
    priority_queue<int> heap;
    for (const auto x : nums) {
      heap.push(x);
    }
    LL ans = 0;
    while (k--) {
      int x = heap.top();
      ans += x;
      heap.pop();
      x = (x + 2) / 3;
      heap.push(x);
      //   cout << ans << '\n';
    }
    return ans;
  }
};
