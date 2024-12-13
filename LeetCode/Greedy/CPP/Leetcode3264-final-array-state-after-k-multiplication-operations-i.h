class Solution {
 public:
  using PII = pair<int, int>;
  vector<int> getFinalState(vector<int> &nums, int k, int multiplier) {
    priority_queue<PII, vector<PII>, greater<>> heap;
    for (int i = 0; i < nums.size(); i++) {
      heap.emplace(nums[i], i);
    }
    while (k--) {
      auto [val, i] = heap.top();
      heap.pop();
      val *= multiplier;
      heap.emplace(val, i);
    }
    vector<int> ans(nums.size());
    while (!heap.empty()) {
      auto [x, i] = heap.top();
      heap.pop();
      ans[i] = x;
    }
    return ans;
  }
};
