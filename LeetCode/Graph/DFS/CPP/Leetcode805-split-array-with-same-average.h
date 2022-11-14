#include <algorithm>
#include <functional>
#include <numeric>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  bool splitArraySameAverage(vector<int>& nums) {
    if (nums.size() == 1) return false;
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int n = nums.size();
    for (auto& x : nums) x = x * n - sum;
    unordered_multiset<int> st;
    int mid = n / 2;
    std::function<void(int, int, int)> dfs_aft = [&](int u, int n, int sum) {
      if (u == n)
        st.insert(sum);
      else {
        dfs_aft(u + 1, n, sum);
        dfs_aft(u + 1, n, sum + nums[u]);
      }
    };
    std::function<bool(int, int, int, int)> dfs_pre = [&](int u, int n, int sum, int cnt) {
      if (u == n) {
        if (cnt && cnt < n && st.count(-sum)) return true;
        return false;
      }
      if (dfs_pre(u + 1, n, sum, cnt)) return true;
      if (dfs_pre(u + 1, n, sum + nums[u], cnt + 1)) return true;
      return false;
    };
    dfs_aft(mid, n, 0);
    int em = 0, full = accumulate(nums.begin() + mid, nums.end(), 0);
    st.erase(st.find(em));
    if (st.count(0)) return true;
    st.insert(em), st.erase(st.find(full));
    if (st.count(-accumulate(nums.begin(), nums.begin() + mid, 0))) return true;
    return dfs_pre(0, mid, 0, 0);
  }
};
