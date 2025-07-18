class Solution {
 public:
  using LL = long long;
  long long minimumDifference(vector<int> &nums) {
    int n = nums.size() / 3;
    vector<LL> fl(nums.size()), fr(nums.size());
    priority_queue<int> heap;
    for (int i = 0; i < n; ++i) {
      fl[n - 1] += nums[i];
      heap.push(nums[i]);
    }
    // cout << "fl " << n - 1 << ": " << fl[n - 1] << '\t';
    for (int i = n; i < nums.size(); ++i) {
      heap.push(nums[i]);
      auto t = heap.top();
      heap.pop();
      fl[i] = (fl[i - 1] + nums[i] - t);
      //   cout << "fl " << i << ": " << fl[i] << '\t';
    }
    // cout << '\n';
    priority_queue<int, vector<int>, greater<>> heap2;
    for (int i = nums.size() - 1; i >= nums.size() - n; i--) {
      fr[nums.size() - n] += nums[i];
      heap2.push(nums[i]);
    }
    // cout << "fr " << nums.size() - n << ": " << fr[nums.size() - n] << '\t';
    for (int i = nums.size() - n - 1; i >= 0; i--) {
      heap2.push(nums[i]);
      auto t = heap2.top();
      heap2.pop();
      fr[i] = (fr[i + 1] + nums[i] - t);
      //   cout << "fr " << i << ": " << fr[i] << '\t';
    }
    // cout << '\n';
    LL ans = LONG_LONG_MAX;
    for (int i = n - 1; i < nums.size() - n; ++i) {
      ans = min(ans, fl[i] - fr[i + 1]);
    }
    return ans;
  }
};
